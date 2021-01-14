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

map<pair<ll, ll>, ll> dp;

ll solve(const ll X, const ll Y) {
    vector<ll> ys;

    if (dp.find(make_pair(X, Y)) != dp.end()) {
        return dp[make_pair(X, Y)];
    }

#ifdef DEBUG
    printf("[solve] X: %lld, Y: %lld\n", X, Y);
#endif

    if (Y == 0) {
        return INF;
    }

    {
        ll y = Y;
        while (y % 2 == 0) {
            ys.push_back(y);
            y /= 2;
        }
        ys.push_back(y);
    }

    ll ans = INF;
    for (int i = 0; i < (int) ys.size(); i++) {
        ll cand = abs(X - ys[i]) + i;
#ifdef DEBUG
        printf("  X: %lld, y: %lld, cand: %lld\n", X, ys[i], cand);
#endif
        chmin(ans, cand);
    }

    if ((int) ys.size() > 1) {
        ll y = ys[ys.size() - 1];
        if (y != 1) {
            chmin(ans, solve(X, y - 1) + ((ll) ys.size()) - 1 + 1);
            chmin(ans, solve(X, y + 1) + ((ll) ys.size()) - 1 + 1);
        }
    }

    dp[make_pair(X, Y)] = ans;
    return ans;
}

int main(void) {
    ll X, Y;
    cin >> X >> Y;

    if (X >= Y) {
        cout << X - Y << endl;
        return 0;
    }

    ll ans = INF;

    if (Y % 2 == 0) {
        chmin(ans, solve(X, Y));
    } else {
        chmin(ans, solve(X, Y - 1) + 1);
        chmin(ans, solve(X, Y + 1) + 1);
    }

    cout << ans << endl;
    return 0;
}
