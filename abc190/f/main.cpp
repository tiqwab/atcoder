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

const int MAX_N = 300005;
SegmentTree<int, int> *st;

vector<int> as;

int main(void) {
    auto f = [](int x, int y) {
        return x + y;
    };
    st = new SegmentTree<int, int>(MAX_N + 1, 0, f);

    int N;
    cin >> N;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    ll inv_num = 0;
    for (int i = 0; i < N; i++) {
        const int a = as[i];
        inv_num += st->query(a + 1, MAX_N);
        const int cur_cnt = st->query(a, a + 1);
        st->update(a, cur_cnt + 1);
    }
    printf("%lld\n", inv_num);

    for (int i = 0; i < N - 1; i++) {
        const int x = as[i];
        inv_num += (N - 1) - x;
        inv_num -= x;
        printf("%lld\n", inv_num);
    }

    delete st;
    return 0;
}
