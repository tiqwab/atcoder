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

const int MAX_N = 300;
const int MAX_K = 300;

ll dp[MAX_N + 2][MAX_K + 2][2]; // [0] = value, [1] = actual hight

void print_dp(int n, int k, ll table[MAX_N + 2][MAX_K + 2][2]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cout << table[i][j][0] << " ";
        }
        cout << endl;
    }
}

int main(void) {
    int N, K;
    cin >> N >> K;

    vector<int> h(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> h[i];
    }

    for (int i = 1; i < MAX_N + 2; i++) {
        for (int j = 1; j < MAX_K + 2; j++) {
            dp[i][j][0] = LONG_LONG_MAX;
        }
    }

    for (int n = 1; n <= N; n++) {
        dp[n][0][0] =  dp[n - 1][0][0] + max(0, h[n] - h[n - 1]);
        dp[n][0][1] = h[n];
        for (int k = 1; k <= K; k++) {
            ll a = dp[n - 1][k][0] + max(0LL, h[n] - dp[n - 1][k][1]);
            ll b = dp[n - 1][k - 1][0];
            if (a < b) {
                dp[n][k][0] = a;
                dp[n][k][1] = h[n];
            } else {
                dp[n][k][0] = b;
                dp[n][k][1] = dp[n - 1][k - 1][1];
            }
        }
    }

    // print_dp(N + 1, K + 1, dp);

    cout << dp[N][K][0] << endl;
    
    return 0;
}
