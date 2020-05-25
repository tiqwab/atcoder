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

const int INF = (int) ((1LL << 31) - 1);

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


const int MAX_A = int(1e9);

vector<int> as;

bool cond(const int v, const int N) {
    vector<int> bs(N);
    for (int i = 0; i < N; i++) {
        if (as[i] < v) {
            bs[i] = 0;
        } else {
            bs[i] = 1;
        }
    }

    vector<int> ss(N + 1, 0);
    for (int i = 0; i < N; i++) {
        ss[i + 1] = ss[i] + bs[i];
    }

    auto f = [](int x, int y) {
        return x + y;
    };
    SegmentTree<int, int> *st = new SegmentTree<int, int>(2 * N, 0, f);
    ll acc = 0;
    for (int i = 0; i <= N; i++) {
        int x = 2 * ss[i] - i + N; // 0 <= ss[i] - i + N <= N
        // printf("x: %d, += %d\n", x, st->query(0, x + 1));
        acc += st->query(0, x + 1);

        int cnt = st->query(x, x + 1);
        st->update(x, cnt + 1);
    }

    const ll lim = ((ll(N) * (ll(N) + 1LL) / 2LL) + 2LL - 1LL) / 2LL;
    // printf("v: %d, cnt: %d, lim: %d\n", v, acc, lim);
    return acc >= lim;
}

int solve(const int N) {
    int left = 0, right = MAX_A + 1, mid;
    while (right - left > 1) {
        mid = left + (right - left) / 2;
        if (cond(mid, N)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return left;
}

int main(void) {
    int N;
    cin >> N;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    cout << solve(N) << endl;

    return 0;
}
