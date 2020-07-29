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

vector<ll> as;
vector<ll> dp;

int main(void) {
    int N;
    cin >> N;

    as.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> as[i];
    }

    dp.resize(N + 1);
    dp[1] = 1000;

    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1];
        for (int j = 1; j < i; j++) {
            ll stocks = dp[j] / as[j];
            chmax(dp[i], dp[j] - stocks * as[j] + stocks * as[i]);
        }
    }

    // for (auto x : dp) {
    //     cout << x << " ";
    // }
    // cout << endl;

    cout << dp[N] << endl;

    return 0;
}
