// #include <algorithm>
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

const int MAX_N = 200000;

SegmentTree<pair<int, int>, pair<int, int>> *st;

int main(void) {
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    auto f = [](pair<int, int> x, pair<int, int> y) {
        pair<int, int> ans;
        ans.first = x.first + y.first;
        ans.second = min(x.second, x.first + y.second);
        return ans;
    };
    st = new SegmentTree<pair<int, int>, pair<int, int>>(MAX_N + 1, make_pair(0, 0), f);

    for (int i = 0; i < N; i++) {
        if (S[i] == '(') {
            st->update(i, make_pair(1, 0));
        } else {
            st->update(i, make_pair(-1, -1));
        }
    }

    for (int i = 0; i < Q; i++) {
        int q, l, r;
        cin >> q >> l >> r;

        if (q == 1) {
            l--;
            r--;
            auto l_v = st->query(l, l + 1);
            auto r_v = st->query(r, r + 1);
            st->update(l, r_v);
            st->update(r, l_v);
        } else {
            l--;
            if (st->query(l, r) == make_pair(0, 0)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }

    delete st;
    return 0;
}
