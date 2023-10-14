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

int main(void) {
    int N;
    cin >> N;

    vector<int> as;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        as.push_back(a);
    }

    // dp[i][j][k]
    // i = vertex
    // j = 1 if choose the edge
    // k = 1 if choose the first edge
    vector<vector<vector<ll>>> dp(N, vector<vector<ll>>(2, vector<ll>(2, INF)));
    dp[0][0][0] = 0;
    dp[0][1][1] = as[0];

    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                const ll edge_cost = as[i + 1];
                if (j == 0) {
                    chmin(dp[i + 1][1][k], dp[i][j][k] + edge_cost);
                } else {
                    chmin(dp[i + 1][0][k], dp[i][j][k]);
                    chmin(dp[i + 1][1][k], dp[i][j][k] + edge_cost);
                }
            }
        }
    }

    // for vertex N - 1
    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 2; k++) {
            const ll edge_cost = as[N - 1];
            if (j == 0) {
                chmin(dp[N - 1][1][k], dp[N - 2][j][k] + edge_cost);
            } else {
                if (k == 0) {
                    chmin(dp[N - 1][1][k], dp[N - 2][j][k] + edge_cost);
                } else {
                    chmin(dp[N - 1][0][k], dp[N - 2][j][k]);
                }
            }
        }
    }

    ll ans = INF;
    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 2; k++) {
            chmin(ans, dp[N - 1][j][k]);
        }
    }
    printf("%lld\n", ans);

    return 0;
}
