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

const int MAX_H = 200000;
const int MAX_W = 200000;

// rows[i] contains obs at row i
vector<multiset<int>> rows;
// col[i] contains obs at col i
vector<multiset<int>> cols;

SegmentTree<int, int> *st;

int main(void) {
    int H, W, M;
    cin >> H >> W >> M;

    rows.resize(H + 1);
    cols.resize(W + 1);

    for (int i = 0; i < M; i++) {
        int h, w;
        cin >> h >> w;
        rows[h].insert(w);
        cols[w].insert(h);
    }

    for (int h = 1; h <= H; h++) {
        rows[h].insert(W + 1);
    }

    for (int w = 1; w <= W; w++) {
        cols[w].insert(H + 1);
    }

#ifdef DEBUG
    printf("rows: \n");
    for (int i = 1; i <= H; i++) {
        printf("  %d: ", i);
        for (auto x : rows[i]) {
            printf("%d ", x);
        }
        printf("\n");
    }
    printf("\n");
    printf("cols: \n");
    for (int i = 1; i <= W; i++) {
        printf("  %d: ", i);
        for (auto x : cols[i]) {
            printf("%d ", x);
        }
        printf("\n");
    }
    printf("\n");
#endif

    ll cnt = 0;

    //
    // count based on col
    //
    {
        const int col_first_obj = *(rows[1].begin());
        for (int w = 1; w < col_first_obj; w++) {
            cnt += *(cols[w].begin()) - 1;
        }
    }

    //
    // count based on row
    //
    {
        auto f = [](int x, int y) {
            return x + y;
        };
        st = new SegmentTree<int, int>(MAX_H + 10, 0, f);

        const int row_first_obj = *(cols[1].begin());

        for (int h = 1; h < row_first_obj; h++) {
            int col_first_obj = *(rows[h].begin());
            cnt += st->query(1, col_first_obj);

            if (h == 1) {
                for (int w = col_first_obj; w <= W; w++) {
                    st->update(w, 1);
                }
            } else {
                for (auto w : rows[h]) {
                    st->update(w, 1);
                }
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
