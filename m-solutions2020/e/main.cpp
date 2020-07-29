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

const ll INF = LONG_LONG_MAX / 2;

vector<int> xs;
vector<int> ys;
vector<int> ps;

// memo_x[bits][city] means the minimum cost for city considering only lines parallel to y axis and included in bits
vector<vector<ll>> memo_x;
// memo_y is almost same as memo_x but lines are parallel to x axis
vector<vector<ll>> memo_y;

// Calculate score for chosen lines.
ll calc(vector<int> &lxs, vector<int> &lys, const int num_line, const int num_city) {
    ll ans = 0;

#ifdef DEBUG
    printf("lxs: ");
    for (auto x : lxs) {
        cout << x << " ";
    }
    cout << endl;
    printf("lys: ");
    for (auto y : lys) {
        cout << y << " ";
    }
    cout << endl;
#endif

    int bits_x = 0, bits_y = 0;
    for (auto lx : lxs) {
        bits_x += 1 << lx;
    }
    for (auto ly : lys) {
        bits_y += 1 << ly;
    }

    for (int i = 0; i < num_city; i++) {
        ans += min(memo_x[bits_x][i], memo_y[bits_y][i]);
    }

#ifdef DEBUG
    cout << "ans: " << ans << endl;
#endif
    return ans;
}

// Choose lines.
// xs contains line parallel to x axis.
// ys contains line parallel to y axis.
ll h(int pos, vector<int> &lxs, vector<int> &lys, const int num_line, const int num_city, const vector<int> &acc_city) {
    if (pos >= num_line) {
        return calc(lxs, lys, num_line, num_city);
    }

    ll cand = INF;
    const int cur_city = acc_city[pos];
    lxs.push_back(cur_city);
    chmin(cand, h(pos + 1, lxs, lys, num_line, num_city, acc_city));
    lxs.pop_back();
    lys.push_back(cur_city);
    chmin(cand, h(pos + 1, lxs, lys, num_line, num_city, acc_city));
    lys.pop_back();

    return cand;
}

// Calculate the best score for chosen cities.
// Each city has at least one line.
ll g(const int num_line, const int num_city, const vector<int> &acc_city) {
#ifdef DEBUG
    for (auto city : acc_city) {
        cout << city << " ";
    }
    cout << endl;
#endif

    vector<int> lxs;
    vector<int> lys;

    return h(0, lxs, lys, num_line, num_city, acc_city);
}

// Choose cities
ll f(int cur, const int num_line, const int num_city, vector<int> &acc_city) {
    if ((int) acc_city.size() == num_line) {
        return g(num_line, num_city, acc_city);
    }
    if (cur >= num_city) {
        return INF;
    }

    ll cand = INF;

    acc_city.push_back(cur);
    chmin(cand, f(cur + 1, num_line, num_city, acc_city));
    acc_city.pop_back();
    chmin(cand, f(cur + 1, num_line, num_city, acc_city));

    return cand;
}

void prepare_memo(const int N) {
    memo_x.resize(1 << N, vector<ll>(N, INF));
    memo_y.resize(1 << N, vector<ll>(N, INF));

    for (int bits = 0; bits < (1 << N); bits++) {
        // 1 is for x, 0 is for y
        const int bits_x = bits;
        const int bits_y = ((1 << N) - 1) ^ bits_x;

        auto func = [](const int bits, const vector<int> &vs, const vector<int> &ps, const int N,
                vector<vector<ll>> &memo) {
            for (int city = 0; city < N; city++) {
                ll cand = INF;
                for (int i = 0; i < N; i++) {
                    if (bits & (1 << i)) {
                        chmin(cand, ll(abs(vs[city] - vs[i])) * ps[city]);
                    }
                }
                {
                    chmin(cand, ll(abs(vs[city] - 0)) * ps[city]);
                }
                memo[bits][city] = cand;
            }
        };

        func(bits_x, xs, ps, N, memo_x);
        func(bits_y, ys, ps, N, memo_y);
    }
}

int main(void) {
    int N;
    cin >> N;

    xs.resize(N);
    ys.resize(N);
    ps.resize(N);
    for (int i = 0; i < N; i++) {
        int X, Y, P;
        cin >> X >> Y >> P;
        xs[i] = X;
        ys[i] = Y;
        ps[i] = P;
    }

    prepare_memo(N);

    for (int k = 0; k <= N; k++) {
        // printf("k: %d\n", k);
        vector<int> acc_city;
        cout << f(0, k, N, acc_city) << endl;
    }

    return 0;
}
