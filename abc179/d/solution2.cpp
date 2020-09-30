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

    dp.resize(2 * (N + 1), 0);
    ss.resize(2 * (N + 1), 0);
    ss[1] = 1;
    ss[2] = MOD - 1;

    ll acc = 0;
    for (int i = 1; i <= N; i++) {
        acc = (acc + ss[i]) % MOD;
        dp[i] = acc;
#ifdef DEBUG
        printf("dp[%d]: %lld\n", i, acc);
#endif
        for (auto area : areas) {
            int l = area.first;
            int r = area.second;
            ss[i + l] = (ss[i + l] + acc) % MOD;
            ss[i + r] = ((ss[i + r] - acc) + MOD) % MOD;
#ifdef DEBUG
            printf("ss[%d]: %lld, ss[%d]: %lld\n", i + l, ss[i + l], i + r, ss[i + r]);
#endif
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
