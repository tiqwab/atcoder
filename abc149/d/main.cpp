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

const ll INF = LONG_MAX;

ll solve(const ll R, const ll S, const ll P, const vector<char> as) {
    int len = (int) as.size();
    vector<vector<ll> > dp(len, vector<ll>(3, 0)); // 0: r, 1: s, 2: p
    ll point;
    if (as[0] == 'r') {
        point = P;
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[0][2] = point;
    } else if (as[0] == 's') {
        point = R;
        dp[0][0] = point;
        dp[0][1] = 0;
        dp[0][2] = 0;
    } else {
        point = S;
        dp[0][0] = 0;
        dp[0][1] = point;
        dp[0][2] = 0;
    }

    for (int i = 1; i < len; i++) {
        ll point;
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]);

        if (as[i] == 'r') {
            point = P;
            dp[i][2] += point;
        } else if (as[i] == 's') {
            point = R;
            dp[i][0] += point;
        } else {
            point = S;
            dp[i][1] += point;
        }
    }

    return max(max(dp[len - 1][0], dp[len - 1][1]), dp[len - 1][2]);
}

int main(void) {
    ll N, K;
    cin >> N >> K;

    ll R, S, P;
    cin >> R >> S >> P;

    string T;
    cin >> T;

    vector<vector<char> > ass(K);
    for (int i = 0; i < N; i++) {
        ass[i % K].push_back(T[i]);
    }

    ll ans = 0;
    for (int i = 0; i < K; i++) {
        // for (int j = 0; j < (int) ass[i].size(); j++) {
        //     cout << ass[i][j] << " ";
        // }
        // cout << endl;
        ans += solve(R, S, P, ass[i]);
    }

    cout << ans << endl;

    return 0;
}
