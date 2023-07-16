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

const int MAX_N = 50;
const int MAX_M = 50;
const int MAX_K = 2500;

const ll MOD = 998244353LL;

int main(void) {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<ll>> dp(N + 1, vector<ll>(K + 1, 0));
    dp[0][0] = 1;

    for (int n = 0; n < N; n++) {
        for (int k = 0; k <= K; k++) {
            for (int m = 1; m <= M; m++) {
                if (k + m <= K) {
                    dp[n + 1][k + m] = (dp[n + 1][k + m] + dp[n][k]) % MOD;
                }
            }
        }
    }

#ifdef DEBUG
    for (int i = 0; i < N + 1; i++) {
        for (int j = 0;j  < K + 1; j++) {
            printf("%lld ", dp[i][j]);
        }
        printf("\n");
    }
#endif

    ll ans = 0;
    for (int k = 0; k <= K; k++) {
        ans = (ans + dp[N][k]) % MOD;
    }

    cout << ans << endl;

    return 0;
}
