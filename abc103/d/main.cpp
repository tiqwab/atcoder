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

// ref. arihon 3-3
// E: type of data, R: type of query result
template<typename E, typename R>
class SegmentTree {
    public:
        SegmentTree(const int _n, const E inf, R (*f)(E, E)): f(f), inf(inf) {
            n = 1;
            while (n < _n) n *= 2;
            data.resize(2 * n, inf);
        }

        // update data[k] with a
        // 0-index, [0, _n) in other words
        // time complexity: O(n)
        void update(int k, E a) {
            k += n - 1;
            data[k] = a;
            while (k > 0) {
                k = (k - 1) / 2;
                data[k] = (*f)(data[k * 2 + 1], data[k * 2 + 2]);
            }
        }

        // query value from [a, b)
        // 0-index, [0, _n) in other words
        // time complexity: O(n)
        R query(int a, int b) {
            return query(a, b, 0, 0, n);
        }

    private:
        int n;
        R (*f)(E, E);
        const E inf;
        vector<E> data;

        R query(int a, int b, int k, int l, int r) {
            // if [a, b) intersect [l, r) = empty
            if (r <= a || b <= l) {
                return inf;
            }

            // if [a, b) includes [l, r)
            if (a <= l && r <= b) {
                return data[k];
            } else {
                R vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
                R vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
                return (*f)(vl, vr);
            }
        }
};

const int MAX_N = 100000;

int N, M;
vector<int> as;
vector<int> bs;

vector<set<int>> ss;
vector<set<int>> es;

SegmentTree<int, int> *st;

int solve(const int N, const int M) {
    for (int i = 0; i < N; i++) {
        for (auto island : es[i]) {
            int a = as[island];
            int b = bs[island];
            if (st->query(a, b) == 0) {
                // printf("add wall to %d\n", b - 1);
                st->update(b - 1, 1);
            }
        }

    }

    return st->query(0, N);
}

int main(void) {
    cin >> N >> M;

    as.resize(M);
    bs.resize(M);
    ss.resize(N);
    es.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        as[i] = a;
        bs[i] = b;

        ss[a].insert(i);
        es[b].insert(i);
    }

    auto f = [](int x, int y) {
        return x + y;
    };
    st = new SegmentTree<int, int>(MAX_N, 0, f);

    cout << solve(N, M) << endl;

    delete st;
    return 0;
}
