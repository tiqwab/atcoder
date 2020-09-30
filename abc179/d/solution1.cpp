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

vector<pair<int, int>> areas;
vector<ll> dp;
vector<ll> ss;

const ll MOD = 998244353LL;

int main(void) {
    int N, K;
    cin >> N >> K;

    areas.resize(K);
    for (int i = 0; i < K; i++) {
        int l, r;
        cin >> l >> r;
        r++;
        areas[i] = make_pair(l, r);
    }

    dp.resize(N + 1, 0);
    dp[1] = 1;
    ss.resize(N + 2, 0);
    ss[1] = ss[0] + dp[1];

    for (int i = 2; i <= N; i++) {
#ifdef DEBUG
        printf("i: %d\n", i);
#endif
        for (int j = 0; j < K; j++) {
            const int area_l = areas[j].first;
            const int area_r = areas[j].second;
#ifdef DEBUG
            printf("  area_l: %d, area_r: %d\n", area_l, area_r);
#endif

            const int l = max(i - area_r, 0);
            const int r = max(i - area_l, 0);
            ll x = (ss[r] - ss[l] + MOD) % MOD;
#ifdef DEBUG
            printf("    l: %d, r: %d, x: %lld\n", l, r, x);
#endif
            dp[i] = (dp[i] + x) % MOD;
            ss[i] = ss[i - 1] + dp[i];
        }
    }

#ifdef DEBUG
    for (int i = 0; i <= N; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
#endif

    cout << dp[N] << endl;
    return 0;
}
