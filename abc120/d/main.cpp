#include <algorithm>
#include <iostream>
#include <vector>

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
        int find(int x) {
            if (d[x] < 0) return x;
            return d[x] = find(d[x]);
        }

        // Return false if x and y are alreday in the same group, otherwise return true.
        // 0-index, [0, n) in other words
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
        bool same(int x, int y) {
            return find(x) == find(y);
        }

        // 0-index, [0, n) in other words
        int size(int x) {
            return -d[find(x)];
        }

    private:
        vector<int> d;
};

vector<pair<int, int>> bridges;

int main(void) {
    int N, M;
    cin >> N >> M;

    bridges.resize(M);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        bridges[i] = {a, b};
    }
    reverse(bridges.begin(), bridges.end());

    UnionFind uf(N);

    vector<ll> ans(M + 1, 0);
    for (int i = 0; i < M; i++) {
        int a = bridges[i].first;
        int b = bridges[i].second;
        ll na = (ll) uf.size(a);
        ll nb = (ll) uf.size(b);
        if (uf.unite(a, b)) {
            ans[i + 1] = ans[i] + na * nb;
        } else {
            ans[i + 1] = ans[i];
        }
    }

    ll reachable_pairs_num = ans[M];
    // printf("reachable_pairs_num: %lld\n", reachable_pairs_num);
    for (int i = M - 1; i >= 0; i--) {
        ans[i] = reachable_pairs_num - ans[i];
        cout << ans[i] << endl;
    }

    return 0;
}
