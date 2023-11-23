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

int main(void) {
    int N;
    cin >> N;

    map<int, int> ms;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        ms[x]++;
    }
    vector<pair<int, int>> ps;
    for (auto m : ms) {
        ps.push_back(make_pair(m.first, m.second));
    }
    const int plen = (int) ps.size();

    vector<vector<ll>> dp(plen + 1, vector<ll>(4, 0));
    for (int i = 0; i <= plen; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i < plen + 1; i++) {
        for (int j = 0; j < 4; j++) {
            // not use
            dp[i][j] = dp[i - 1][j];

            // use
            if (j > 0) {
                dp[i][j] += dp[i - 1][j - 1] * ps[i - 1].second;
            }
        }
    }

#ifdef DEBUG
    for (auto xs : dp) {
        for (auto x : xs) {
            printf("%lld ", x);
        }
        printf("\n");
    }
    printf("\n");
#endif

    printf("%lld\n", dp[plen][3]);

    return 0;
}
