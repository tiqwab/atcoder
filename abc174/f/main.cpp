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

const int MAX_N = 500000;

SegmentTree<int, int> *st;

vector<int> cs;

// nexts[i] points to the index of cs whose color is same as i
vector<int> nexts;

// ref. https://qiita.com/tanakh/items/a312a9bd684658ab1e7b
int main(void) {
    int N, Q;
    cin >> N >> Q;

    auto f = [](int x, int y) {
        return x + y;
    };
    st = new SegmentTree<int, int>(N + 1, 0, f);

    cs.resize(N);
    for (int i = 0; i < N; i++) {
        int c;
        cin >> c;
        c--;
        cs[i] = c;
    }

    nexts.resize(N, -1);
    {
        vector<int> color_to_pos(N, -1);
        for (int i = 0; i < N; i++) {
            if (color_to_pos[cs[i]] != -1) {
                nexts[color_to_pos[cs[i]]] = i;
            } else {
                st->update(i, 1);
            }
            color_to_pos[cs[i]] = i;
        }
    }

#ifdef DEBUG
    printf("nexts: ");
    for (int i = 0; i < N; i++) {
        cout << nexts[i] << " ";
    }
    cout << endl;

    printf("st: ");
    for (int i = 0; i < N; i++) {
        cout << st->query(i, i + 1) << " ";
    }
    cout << endl;
#endif

    vector<pair<pair<int, int>, int>> qs(Q);
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        qs[i] = make_pair(make_pair(l, r), i);
    }
    sort(qs.begin(), qs.end());

    vector<int> ans(Q);
    int qi = 0;
    for (int cur = 0; cur < N; cur++) {
        while (1) {
            if (qi >= Q) {
                break;
            }
            pair<int, int> lr = qs[qi].first;
            int orig_qi = qs[qi].second;
            if (lr.first > cur) {
                break;
            }

#ifdef DEBUG
            printf("process query %d [%d, %d)\n", qi, lr.first, lr.second);
#endif

            ans[orig_qi] = st->query(lr.first, lr.second);
            qi++;
        }
        st->update(cur, 0);
        if (nexts[cur] != -1) {
            st->update(nexts[cur], 1);
        }

#ifdef DEBUG
        printf("st: ");
        for (int i = 0; i < N; i++) {
            cout << st->query(i, i + 1) << " ";
        }
        cout << endl;
#endif
    }

    for (int i = 0; i < Q; i++) {
        cout << ans[i] << endl;
    }

    delete st;
    return 0;
}
