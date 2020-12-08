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

SegmentTree<int, int> *st;

vector<int> ps;

void solve(const int N) {
    vector<int> qs;
    qs.push_back(0);
    for (auto x : ps) {
        qs.push_back(x);
    }
    qs.push_back(N + 1);

    queue<int> q;

    for (int i = 0; i < (int) qs.size() - 1; i++) {
        if (qs[i] > qs[i + 1]) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        const int idx = q.front();
        q.pop();
        printf("%d\n", idx);
        swap(qs[idx], qs[idx + 1]);
        if (qs[idx - 1] > qs[idx]) {
            q.push(idx - 1);
        }
        if (qs[idx + 1] > qs[idx + 2]) {
            q.push(idx + 1);
        }
    }
}

int main(void) {
    int N;
    cin >> N;

    ps.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> ps[i];
    }

    auto f = [](int x, int y) {
        return x + y;
    };
    st = new SegmentTree<int, int>(N + 1, 0, f);

    ll invs = 0LL;
    for (int i = 0; i < N; i++) {
        invs += st->query(ps[i] + 1, N + 1);
        st->update(ps[i], 1);
    }

#ifdef DEBUG
    printf("inversion number: %lld\n", invs);
#endif
    if (invs != N - 1) {
        cout << -1 << endl;
        return 0;
    }

    // if there is a number whose position is correct, print -1.
    {
        bool ok = true;
        for (int i = 0; i < N; i++) {
            if (ps[i] == i + 1) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << -1 << endl;
            return 0;
        }
    }

    solve(N);

    delete st;
    return 0;
}
