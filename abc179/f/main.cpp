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

const int MAX_N = 200001;

int main(void) {
    int N, Q;
    cin >> N >> Q;

    auto f = [](int x, int y) {
        return min(x, y);
    };
    SegmentTree<int, int> *stx = new SegmentTree<int, int>(N + 1, INF, f);
    SegmentTree<int, int> *sty = new SegmentTree<int, int>(N + 1, INF, f);

    stx->update(N, N);
    sty->update(N, N);

    ll acc = ll(N - 2) * ll(N - 2);

    for (int i = 0; i < Q; i++) {
        int s, t;
        cin >> s >> t;
        if (s == 1) {
            // put (1, t)
            int r = stx->query(t, N + 1);
            acc -= r - 2;
            sty->update(r, f(sty->query(r, r + 1), t));
            
        } else {
            // put (t, 1)
            int r = sty->query(t, N + 1);
            acc -= r - 2;
            stx->update(r, f(stx->query(r, r + 1), t));
        }

#ifdef DEBUG
        printf("stx: \n");
        for (int i = 0; i <= N; i++) {
            cout << stx->query(i, i + 1) << " ";
        }
        printf("\n");
        printf("sty: \n");
        for (int i = 0; i <= N; i++) {
            cout << sty->query(i, i + 1) << " ";
        }
        printf("\n");
#endif
    }

    cout << acc << endl;
    
    delete stx;
    delete sty;
    return 0;
}
