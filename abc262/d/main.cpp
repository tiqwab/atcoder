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

const ll MOD = 998244353LL;

int main(void) {
    int N;
    cin >> N;

    vector<ll> as;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        as.push_back(a);
    }

    ll ans = 0;

    for (int p = 1; p <= N; p++) {
#ifdef DEBUG
        printf("p=%d\n", p);
#endif
        vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(p + 1, vector<ll>(p, 0)));
        dp[0][0][0] = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= p; j++) {
                for (int k = 0; k < p; k++) {
                    if (dp[i][j][k] > 0) {
                        // not choose
                        dp[i + 1][j][k] = (dp[i + 1][j][k] + dp[i][j][k]) % MOD;

                        // choose
                        if (j + 1 <= p) {
                            dp[i + 1][j + 1][(k + as[i]) % p] = (dp[i + 1][j + 1][(k + as[i]) % p] + dp[i][j][k]) % MOD;
                        }
                    }
                }
            }
#ifdef DEBUG
            printf("dp: \n");
            for (int j = 0; j <= p; j++) {
                for (int k = 0; k < p; k++) {
                    printf("%lld ", dp[i + 1][j][k]);
                }
                printf("\n");
            }
#endif
        }
        ans = (ans + dp[N][p][0]) % MOD;
    }

    printf("%lld\n", ans);

    return 0;
}
