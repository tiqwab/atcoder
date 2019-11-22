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

ll dp1[MAX_N + 2][MAX_T + 2];
ll dp2[MAX_N + 2][MAX_T + 2];

void print_dp(int N, int T, ll dp[MAX_N + 2][MAX_T + 2]) {
    for (int n = 1; n <= N; n++) {
        for (int t = 1; t <= T; t++) {
            cout << dp[n][t] << " ";
        }
        cout << endl;
    }
}

/*
 * Based on solution 1.
 * ref. https://img.atcoder.jp/abc145/editorial.pdf
 */
int main(void) {
    int N, T;
    cin >> N >> T;
    
    vector<pair<int, int> > dishes(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        dishes[i] = {a, b};
    }

    memset(dp1, 0, sizeof(ll) * (MAX_N + 2) * (MAX_T + 2));
    memset(dp2, 0, sizeof(ll) * (MAX_N + 2) * (MAX_T + 2));

    for (int n = 1; n <= N; n++) {
        for (int t = 1; t <= T; t++) {
            if (dishes[n - 1].first <= t) {
                dp1[n][t] = max(dp1[n - 1][t], dp1[n - 1][t - dishes[n - 1].first] + dishes[n - 1].second);
            } else {
                dp1[n][t] = dp1[n - 1][t];
            }
        }
    }

    for (int n = N; n >= 1; n--) {
        for (int t = 1; t <= T; t++) {
            if (dishes[n - 1].first <= t) {
                dp2[n][t] = max(dp2[n + 1][t], dp2[n + 1][t - dishes[n - 1].first] + dishes[n - 1].second);
            } else {
                dp2[n][t] = dp2[n + 1][t];
            }
        }
    }

    ll max = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= T - 1; j++) {
            chmax(max, dp1[i - 1][j] + dp2[i + 1][T - 1 - j] + dishes[i - 1].second);
        }
    }

    // print_dp(N, T, dp1);
    // cout << endl;
    // print_dp(N, T, dp2);
    // cout << endl;

    cout << max << endl;

    return 0;
}
