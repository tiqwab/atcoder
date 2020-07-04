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

vector<ll> as;

// smaller than or equal to as[0]
vector<vector<ll>> dp1;
// bigger than as[0]
vector<vector<ll>> dp2;

ll solve(ll X, ll S) {
    dp1.resize(42, vector<ll>(2, -1));
    dp2.resize(42, vector<ll>(2, -1));

    dp1[0][0] = 0;

    ll A0 = as[0];
    ll v = 1;

    for (int i = 0; i < 41; i++) {
        const int cs = S & 1;
        const int cx = X & 1;
        const int ca0 = A0 & 1;

        for (int j = 0; j < 2; j++) { // carry
#ifdef DEBUG
            printf("cs: %d, cx: %d, ca0: %d, i: %d, j: %d\n", cs, cx, ca0, i, j);
#endif
            for (ll ca = 0; ca < 2; ca++) {
                for (ll cb = 0; cb < 2; cb++) {
                    ll acc = ca + cb + j;
                    if ((acc & 1) != cs) {
                        continue;
                    }
                    if ((ca ^ cb) != cx) {
                        continue;
                    }

                    int ni = i + 1;
                    int nj = acc >= 2;

                    // dp1
                    if (dp1[i][j] != -1) {
                        if (ca <= ca0) {
                            chmax(dp1[ni][nj], dp1[i][j] | (ca * v));
                        } else {
                            chmax(dp2[ni][nj], dp1[i][j] | (ca * v));
                        }
                    }

                    // dp2
                    if (dp2[i][j] != -1) {
                        if (ca < ca0) {
                            chmax(dp1[ni][nj], dp2[i][j] | (ca * v));
                        } else {
                            chmax(dp2[ni][nj], dp2[i][j] | (ca * v));
                        }
                    }
                }
            }
        }

        S >>= 1;
        X >>= 1;
        A0 >>= 1;
        v <<= 1;
    }

    return max(dp1[41][0], dp1[41][1]);
}

// ref. https://atcoder.jp/contests/abc172/submissions/14783201
int main(void) {
    int N;
    cin >> N;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    ll X = 0;
    for (int i = 2; i < N; i++) {
        X ^= as[i];
    }

    ll S = as[0] + as[1];

    ll ans = solve(X, S);
    if (ans <= 0) {
        cout << -1 << endl;
    } else {
        cout << as[0] - ans << endl;
    }

#ifdef DEBUG
    printf("dp1: \n");
    for (int i = 0; i < 42; i++) {
        for (int j = 0; j < 2; j++) {
            cout << dp1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    printf("dp2: \n");
    for (int i = 0; i < 42; i++) {
        for (int j = 0; j < 2; j++) {
            cout << dp2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
#endif

    return 0;
}
