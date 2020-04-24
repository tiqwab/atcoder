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

vector<ll> as;
vector<pair<ll, int>> bs; // {value, initial_pos}
vector<vector<ll>> dp;

void solve(const int N) {
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N - i; j++) {
            auto v = bs[i + j].first;
            auto pos = bs[i + j].second;
            if (i > 0) {
                chmax(dp[i][j], dp[i - 1][j] + v * abs(i - pos));
            }
            if (j > 0) {
                chmax(dp[i][j], dp[i][j - 1] + v * abs(N - j + 1 - pos));
            }
        }
    }
}

// ref. https://kmjp.hatenablog.jp/entry/2020/04/20/0900
int main(void) {
    int N;
    cin >> N;

    as.resize(N + 1);
    bs.resize(N + 1);
    bs[0] = { INF, 0 };
    for (int i = 1; i <= N; i++) {
        cin >> as[i];
        bs[i] = { as[i], i };
    }
    sort(bs.begin(), bs.end());
    reverse(bs.begin(), bs.end());

    dp.resize(N + 1, vector<ll>(N + 1, 0));

    solve(N);

    // for (int i = 0; i <= N; i++) {
    //     for (int j = 0; j <= N; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    ll ans = 0;
    for (int i = 0; i <= N; i++) {
        chmax(ans, dp[i][N - i]);
    }
    cout << ans << endl;

    return 0;
}
