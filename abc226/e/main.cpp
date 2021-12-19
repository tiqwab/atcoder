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

const ll MOD = 998244353;

vector<vector<int>> edges;

void dfs(const int cur, UnionFind &uf) {
    for (auto next : edges[cur]) {
        if (!uf.same(cur, next)) {
            uf.unite(cur, next);
            dfs(next, uf);
        }
    }
}

int main(void) {
    int N, M;
    cin >> N >> M;

    edges.resize(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    UnionFind uf(N);

    for (int i = 0; i < N; i++) {
        if (uf.size(i) == 1) {
            dfs(i, uf);
        }
    }

    ll ans = 1;

    // groups[i] contains nodes in the same group
    map<int, vector<int>> groups;
    for (int i = 0; i < N; i++) {
        groups[uf.find(i)].push_back(i);
    }

    for (auto p : groups) {
        auto group = p.second;
        const int node_count = (int) group.size();

        int edge_count = 0;
        for (auto node : group) {
            edge_count += (int) edges[node].size();
        }
        assert(edge_count % 2 == 0);
        edge_count /= 2;

        if (node_count != edge_count) {
            ans = 0;
            break;
        }

        ans = (ans * 2) % MOD;
    }

    cout << ans << endl;

    return 0;
}
