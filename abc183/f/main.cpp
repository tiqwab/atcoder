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

UnionFind *uf;
vector<int> cs;

vector<map<int, int>> ms;

int main(void) {
    int N, Q;
    cin >> N >> Q;

    cs.resize(N);
    ms.resize(N, map<int, int>());
    for (int i = 0; i < N; i++) {
        int c;
        cin >> c;
        c--;
        cs[i] = c;
        ms[i][cs[i]]++;
    }

    uf = new UnionFind(N);

    for (int i = 0; i < Q; i++) {
        int q, x, y;
        cin >> q >> x >> y;
        x--;
        y--;
        if (q == 1) {
            if (uf->same(x, y)) {
                continue;
            }

            int rx = uf->find(x);
            int ry = uf->find(y);
            uf->unite(x, y);
            int r = uf->find(x);
            if (r != ry) {
                swap(rx, ry);
            }
            for (auto p : ms[rx]) {
                ms[ry][p.first] += p.second;
            }
        } else {
            int rx = uf->find(x);
            printf("%d\n", (ms[rx])[y]);
        }
    }

    delete uf;
    return 0;
}
