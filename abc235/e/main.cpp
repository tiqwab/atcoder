#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>

using namespace std;

typedef long long ll;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

/*
 * ref. [Union-Find](https://www.slideshare.net/chokudai/union-find-49066733)
 * ref. [AtCoder ABC 157 - AtCoder Live](https://www.youtube.com/watch?v=TdR816rqc3s)
 */
class UnionFind {
    public:
        UnionFind(int n = 0): d(n, -1) {}

        // 0-index, [0, n) in other words
        // Time complexity: O(a(n)) (a = inverse Achkermann function)
        int find(int x) {
            if (d[x] < 0) return x;
            return d[x] = find(d[x]);
        }

        // Return false if x and y are alreday in the same group, otherwise return true.
        // 0-index, [0, n) in other words
        // Time complexity: O(a(n)) (a = inverse Achkermann function)
        bool unite(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) return false;
            if (d[x] > d[y]) swap(x, y);
            d[x] += d[y];
            d[y] = x;
            return true;
        }

        // 0-index, [0, n) in other words
        // Time complexity: O(a(n)) (a = inverse Achkermann function)
        bool same(int x, int y) {
            return find(x) == find(y);
        }

        // 0-index, [0, n) in other words
        // Time complexity: O(1)
        int size(int x) {
            return -d[find(x)];
        }

    private:
        vector<int> d;
};


const int INF = INT_MAX / 2;
const int MAX_N = 200010;

// {cost, {v1, v2}}
vector<pair<ll, pair<int, int>>> edges;
set<pair<ll, pair<int, int>>> edges_in_g;

vector<pair<ll, pair<int, int>>> questions;
map<pair<ll, pair<int, int>>, bool> ans;

UnionFind *uf;

int main(void) {
    int N, M, Q;
    cin >> N >> M >> Q;

    for (int i = 0; i < M; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--;
        b--;
        if (a > b) {
            swap(a, b);
        }
        edges.push_back(make_pair(c, make_pair(a, b)));
        edges_in_g.insert(make_pair(c, make_pair(a, b)));
    }

    for (int i = 0; i < Q; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--;
        v--;
        if (u > v) {
            swap(u, v);
        }
        edges.push_back(make_pair(w, make_pair(u, v)));
        questions.push_back(make_pair(w, make_pair(u, v)));
    }

    sort(edges.begin(), edges.end());

    uf = new UnionFind(MAX_N);
    for (auto edge : edges) {
        const ll cost = edge.first;
        const int v1 = edge.second.first;
        const int v2 = edge.second.second;
        if (edges_in_g.find(edge) != edges_in_g.end()) {
            // this edge is in G
            if (!uf->same(v1, v2)) {
                uf->unite(v1, v2);
            }
        } else {
            // this edge comes from question
            ans[edge] = !uf->same(v1, v2);
        }
    }

    for (auto q : questions) {
        if (ans[q]) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}
