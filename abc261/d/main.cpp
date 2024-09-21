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

int main(void) {
    int N, M;
    cin >> N >> M;

    vector<ll> profits;
    for (int i = 0 ; i < N; i++) {
        ll x;
        cin >> x;
        profits.push_back(x);
    }

    map<int, ll> bonus;
    for (int i = 0 ; i < M; i++) {
        int c;
        ll y;
        cin >> c >> y;
        bonus[c] = y;
    }

    // dp[j][k]
    // k: 0 for ura, 1 for omote
    vector<vector<ll>> dp(N + 1, vector<ll>(2, -1));

    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        vector<vector<ll>> tmp(N + 1, vector<ll>(2, -1));

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 2; k++) {
                if (dp[j][k] == -1) {
                    continue;
                }

                // ura
                {
                    ll acc = dp[j][k];
                    chmax(tmp[0][0], acc);
                }

                // omote
                {
                    ll acc = dp[j][k];
                    acc += profits[i];
                    if (bonus.find(j + 1) != bonus.end()) {
                        acc += bonus[j + 1];
                    }
                    chmax(tmp[j + 1][1], acc);
                }
            }
        }

        swap(dp, tmp);
#ifdef DEBUG
    printf("dp: \n");
    for (int j = 0; j < N + 1; j++) {
        for (int k = 0; k < 2; k++) {
            printf("%lld ", dp[j][k]);
        }
        printf("\n");
    }
    printf("\n");
#endif
    }

    ll ans = 0;
    for (int j = 0; j < N + 1; j++) {
        for (int k = 0; k < 2; k++) {
            chmax(ans, dp[j][k]);
        }
    }
    printf("%lld\n", ans);

    return 0;
}

