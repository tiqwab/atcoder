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


// {cost, to}
vector<vector<pair<int, int>>> edges;

ll do_kruskal(const int N, const int M) {
    ll ans = 0;

    UnionFind uf(N);

    // {cost, from, to}
    auto f = [](const tuple<ll, int, int>& one, const tuple<ll, int, int>& other) {
        ll c1;
        int f1, t1;
        ll c2;
        int f2, t2;
        tie(c1, f1, t1) = one;
        tie(c2, f2, t2) = other;
        if (c1 != c2) {
            return c1 > c2;
        } else {
            return make_pair(f1, t1) > make_pair(f2, t2);
        }
    };
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, decltype(f)> q(f);

    for (int i = 0; i < N; i++) {
        for (auto edge : edges[i]) {
            ll c;
            int f, t;
            c = edge.first;
            f = i;
            t = edge.second;
            q.push(make_tuple(c, f, t));
        }
    }

    while (!q.empty()) {
        ll c1;
        int f1, t1;
        auto edge = q.top();
        q.pop();
        tie(c1, f1, t1) = edge;

#ifdef DEBUG
        printf("(%lld, %d, %d)\n", c1, f1, t1);
#endif

        if (uf.same(f1, t1)) {
            if (c1 < 0) {
                ans += c1;
            }
            continue;
        }

        ans += c1;
        uf.unite(f1, t1);
    }

    return ans;
}

int main(void) {
    int N, M;
    cin >> N >> M;

    edges.resize(N);

    ll total_cost = 0;

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges[a].push_back(make_pair(c, b));
        // edges[b].push_back(make_pair(c, a));
        total_cost += c;
    }

    ll mst_cost = do_kruskal(N, M);
#ifdef DEBUG
    printf("mst_cost: %lld\n", mst_cost);
#endif

    cout << max(0LL, (total_cost - mst_cost)) << endl;

    return 0;
}
