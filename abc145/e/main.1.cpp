#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

#include <string.h>

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

const int MAX_N = 3000;
const int MAX_T = 3000;

ll dp1[MAX_N + 1][MAX_T + 1];
ll dp2[MAX_N + 1][MAX_T + 1];

ll solve(int n, int t, ll dp[MAX_N + 1][MAX_T + 1], const vector<pair<int, int> > &dishes) {
    if (dp[n][t] != -1) {
        ; // just return dp[n][t];
    } else if (n == 0 || t == 0) {
        dp[n][t] = 0;
    } else if (dishes[n - 1].first > t) {
        dp[n][t] = solve(n - 1, t, dp, dishes);
    } else {
        dp[n][t] = max(
                solve(n - 1, t - dishes[n - 1].first, dp, dishes) + dishes[n - 1].second,
                solve(n - 1, t, dp, dishes)
                );
    }

    return dp[n][t];
}

void print_dp(int N, int T, ll dp[MAX_N + 1][MAX_T + 1]) {
    for (int n = 1; n <= N; n++) {
        for (int t = 1; t <= T; t++) {
            cout << dp[n][t] << " ";
        }
        cout << endl;
    }
}

int main(void) {
    int n, t;
    cin >> n >> t;
    
    vector<pair<int, int> > dishes(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        dishes[i] = {a, b};
    }
    vector<pair<int, int> > rev_dishes(dishes);
    reverse(rev_dishes.begin(), rev_dishes.end());

    memset(dp1, -1, sizeof(ll) * (MAX_N + 1) * (MAX_T + 1));
    memset(dp2, -1, sizeof(ll) * (MAX_N + 1) * (MAX_T + 1));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= t; j++) {
            solve(i, j, dp1, dishes);
            solve(i, j, dp2, rev_dishes);
        }
    }

    // print_dp(n, t, dp1);
    // cout << endl;
    // print_dp(n, t, dp2);
    // cout << endl;

    ll max = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= t - 1; j++) {
            chmax(max, dp1[i - 1][j] + dp2[n - i][t - 1 - j] + dishes[i - 1].second);
        }
    }

    cout << max << endl;

    return 0;
}
