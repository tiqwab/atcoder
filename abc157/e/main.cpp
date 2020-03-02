#include <algorithm>
#include <iostream>
#include <set>
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

const int MAX_N = 500000;

int bits_count(int x) {
    int res = 0;
    while (x > 0) {
        if (x & 0x1) {
            res++;
        }
        x >>= 1;
    }
    return res;
}

int main(void) {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int Q;
    cin >> Q;

    auto f = [](int x, int y) {
        return x | y;
    };
    SegmentTree<int, int> *st = new SegmentTree<int, int>(N, 0LL, f);

    for (int i = 0; i < N; i++) {
        int c = S[i] - 'a';
        st->update(i, 1 << c);
    }

    for (int i = 0; i < Q; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int b;
            char c;
            cin >> b >> c;
            b--;
            int x = c - 'a';
            st->update(b, (1 << x));
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            cout << bits_count(st->query(l, r)) << endl;
        }
    }

    delete st;
    return 0;
}
