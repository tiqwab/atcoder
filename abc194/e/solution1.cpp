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

const int INF = INT_MAX / 2;
const int MAX_N = 1500000;

vector<int> as;

int check(const int l, const int r, SegmentTree<int, int> *st, const int N, const int M) {
#ifdef DEBUG
    printf("  [%d, %d)\n", l, r);
#endif

    if (r - l == 1) {
        return l;
    }

    const int mid = l + (r - l) / 2;

    const int l_len = mid - l;
    const int l_cnt = st->query(l, mid);
#ifdef DEBUG
    printf("    l_cnt: %d\n", l_cnt);
#endif

    // const int r_len = r - mid;
    // const int r_cnt = st->query(mid, r);

    if (l_cnt < l_len) {
        return check(l, mid, st, N, M);
    } else {
        return check(mid, r, st, N, M);
    }
}

int main(void) {
    int N, M;
    cin >> N >> M;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    map<int, int> counter;

    auto f = [](int x, int y) {
        return x + y;
    };
    SegmentTree<int, int> *st = new SegmentTree<int, int>(MAX_N + 1, 0, f);

    for (int i = 0; i < M - 1; i++) {
        if (counter[as[i]] == 0) {
            st->update(as[i], 1);
        }
        counter[as[i]]++;
    }

    int ans = INF;

    for (int i = M - 1; i < N; i++) {
        if (counter[as[i]] == 0) {
            st->update(as[i], 1);
        }
        counter[as[i]]++;

        int cand = check(0, N + 1, st, N, M);
#ifdef DEBUG
        printf("cand: %d\n", cand);
#endif
        chmin(ans, cand);

        if (counter[as[i - M + 1]] == 1) {
            st->update(as[i - M + 1], 0);
        }
        counter[as[i - M + 1]]--;
    }

    cout << ans << endl;

    return 0;
}
