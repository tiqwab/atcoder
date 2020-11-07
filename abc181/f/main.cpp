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

vector<int> xs;
vector<int> ys;

int main(void) {
    int N;
    cin >> N;

    // index N is for start
    // index N+1 is for end
    xs.resize(N + 2);
    ys.resize(N + 2);
    for (int i = 0; i < N; i++) {
        cin >> xs[i] >> ys[i];
    }

    const int start = N;
    const int end = N + 1;

    auto f = [&](const double r) {
        UnionFind uf(N + 2);

        for (int i = 0; i < N; i++) {
            const double my_x = xs[i];
            const double my_y = ys[i];

            if (my_y > 100 - 2 * r) {
                uf.unite(start, i);
            }
            if (my_y < -100 + 2 * r) {
                uf.unite(end, i);
            }

            for (int j = i + 1; j < N; j++) {
                const double other_x = xs[j];
                const double other_y = ys[j];

                const double diff_x = abs(my_x - other_x);
                const double diff_y = abs(my_y - other_y);
                if (diff_x * diff_x + diff_y * diff_y < 4 * r * r) {
                    uf.unite(i, j);
                }
            }
        }

        return uf.same(start, end);
    };

    double l = 0.0, r = 100.0;
    while (r - l > 0.00001) {
        double mid = (r - l) / 2.0 + l;
        if (f(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    printf("%.5f\n", l);
    return 0;
}
