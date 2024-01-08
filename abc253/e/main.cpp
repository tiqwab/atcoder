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

const ll MOD = 998244353;

int main(void) {
    int N, M, K;
    cin >> N >> M >> K;

    vector<ll> dp(M + 1, 1);
    dp[0] = 0;

    vector<ll> acc(M + 1, 0);
    for (int i = 1; i <= M; i++) {
        acc[i] = (acc[i - 1] + dp[i]) % MOD;
    }

    for (int i = 0; i < N - 1; i++) {
        vector<ll> tmp_dp(M + 1, 0);

        for (int i = 1; i <= M; i++) {
            if (i >= K) {
                tmp_dp[i] = (tmp_dp[i] + acc[i - K]) % MOD;
            }
            if (i <= M - K) {
                tmp_dp[i] = (((tmp_dp[i] + acc[M]) % MOD) - acc[i + K - 1] + MOD) % MOD;
            }
            if (K == 0) {
                tmp_dp[i] = (tmp_dp[i] - dp[i] + MOD) % MOD;
            }
        }

        vector<ll> tmp_acc(M + 1, 0);
        for (int i = 1; i <= M; i++) {
            tmp_acc[i] = (tmp_acc[i - 1] + tmp_dp[i]) % MOD;
        }

#ifdef DEBUG
        printf("tmp_dp: ");
        for (int i = 0; i <= M; i++) {
            printf("%lld ", tmp_dp[i]);
        }
        printf("\n");
        printf("tmp_acc: ");
        for (int i = 0; i <= M; i++) {
            printf("%lld ", tmp_acc[i]);
        }
        printf("\n");
#endif

        swap(tmp_dp, dp);
        swap(tmp_acc, acc);
    }

    ll ans = 0;
    for (int i = 1; i <= M; i++) {
        ans = (ans + dp[i]) % MOD;
    }
    printf("%lld\n", ans);

    return 0;
}
