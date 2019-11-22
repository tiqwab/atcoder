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

void print_dp(int N, int T, ll dp[MAX_N + 2][MAX_T + 2]) {
    for (int n = 1; n <= N; n++) {
        for (int t = 1; t <= T; t++) {
            cout << dp[n][t] << " ";
        }
        cout << endl;
    }
}

/*
 * Based on solution 2.
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
    sort(dishes.begin(), dishes.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.first < b.first;
    });

    memset(dp1, 0, sizeof(ll) * (MAX_N + 2) * (MAX_T + 2));

    // It might be simpler to extend the above limit of T according to dish.
    // In that case, we don't have to calculate max in another loop.
    // ref. https://atcoder.jp/contests/abc145/submissions/8472233
    for (int n = 1; n <= N; n++) {
        for (int t = 1; t <= T; t++) {
            if (dishes[n - 1].first <= t) {
                dp1[n][t] = max(dp1[n - 1][t], dp1[n - 1][t - dishes[n - 1].first] + dishes[n - 1].second);
            } else {
                dp1[n][t] = dp1[n - 1][t];
            }
        }
    }

    ll max = 0;
    for (int i = 1; i <= N; i++) {
        auto max_remain = max_element(dishes.begin() + i, dishes.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
                return a.second < b.second;
        });
        for (int j = 1; j <= T - 1; j++) {
            chmax(max, dp1[i][j] + ((max_remain != dishes.end()) ? max_remain->second : 0));
        }
    }

    // print_dp(N, T, dp1);
    // cout << endl;
    // print_dp(N, T, dp2);
    // cout << endl;

    cout << max << endl;

    return 0;
}
