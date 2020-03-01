#include <algorithm>
#include <iostream>
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

vector<ll> A;
vector<vector<ll>> dp;

int main(void) {
    int N;
    cin >> N;
    A.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    dp.resize(N + 1, vector<ll>(2, -INF));
    dp[0][0] = 0;

    for (int i = 1; i <= N; i++) {
        chmax(dp[i][0], dp[i - 1][0] + A[i]);
        chmax(dp[i][0], dp[i - 1][1] - A[i]);

        chmax(dp[i][1], dp[i - 1][0] - A[i]);
        chmax(dp[i][1], dp[i - 1][1] + A[i]);
    }

    // for (int i = 0; i <= N; i++) {
    //     for (int j = 0; j <= 1; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    cout << dp[N][0] << endl;

    return 0;
}
