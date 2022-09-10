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
    int N;
    cin >> N;

    vector<ll> dp(9, 1);

    for (int i = 1; i < N; i++) {
        vector<ll> tmp_dp(9, 0);

        for (int j = 0; j < 9; j++) {
            if (j != 0) {
                tmp_dp[j] = (tmp_dp[j] + dp[j - 1]) % MOD;
            }
            tmp_dp[j] = (tmp_dp[j] + dp[j]) % MOD;
            if (j != 8) {
                tmp_dp[j] = (tmp_dp[j] + dp[j + 1]) % MOD;
            }
        }

        swap(tmp_dp, dp);
    }

    ll ans = 0;
    for (int i = 0; i < 9; i++) {
        ans = (ans + dp[i]) % MOD;
    }
    printf("%lld\n", ans);

    return 0;
}
