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

const int INF = INT_MAX / 2;

vector<int> dp;

int main(void) {
    ll N;
    cin >> N;

    dp.resize(N + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        if (dp[i] == INF) {
            continue;
        }
        for (ll x = 1; i + x <= N; x *= 6) {
            chmin(dp[i + x], dp[i] + 1);
        }
        for (ll x = 1; i + x <= N; x *= 9) {
            chmin(dp[i + x], dp[i] + 1);
        }
    }

    cout << dp[N] << endl;

    // for (int i = 0; i <= N; i++) {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;

    return 0;
}
