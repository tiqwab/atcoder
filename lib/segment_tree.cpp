#include <algorithm>
#include <iostream>
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
class SegmentTree {
    public:
        SegmentTree(const int _n, int (*f)(int, int)): f(f) {
            n = 1;
            while (n < _n) n *= 2;
            data.resize(2 * n, INF);
        }

        // update data[k] with a
        // time complexity: O(n)
        void update(int k, int a) {
            k += n - 1;
            data[k] = a;
            while (k > 0) {
                k = (k - 1) / 2;
                data[k] = (*f)(data[k * 2 + 1], data[k * 2 + 2]);
            }
        }

        // query value from [a, b)
        // // time complexity: O(n)
        int query(int a, int b) {
            return query(a, b, 0, 0, n);
        }

    private:
        int n;
        int (*f)(int, int);
        vector<int> data;

        int query(int a, int b, int k, int l, int r) {
            // if [a, b) intersect [l, r) = empty
            if (r <= a || b <= l) {
                return INF;
            }

            // if [a, b) includes [l, r)
            if (a <= l && r <= b) {
                return data[k];
            } else {
                int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
                int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
                return min(vl, vr);
            }
        }
};

const int MAX_N = 100000;

// ref. http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
int main(void) {
    int n, q;
    cin >> n >> q;

    auto f = [](int x, int y) {
        return min(x, y);
    };
    SegmentTree *st = new SegmentTree(n, f);

    for (int i = 0; i < q; i++) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) {
            // update
            st->update(x, y);
        } else {
            // find
            cout << st->query(x, y + 1) << endl;
        }
    }

    delete st;
    return 0;
}
