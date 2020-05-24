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
const ll MAX_COST = 1000 * 1000 * 1000;

static ll do_solve(map<ll, ll> &dp, const ll n, const ll A, const ll B, const ll C, const ll D) {
    if (dp.find(n) != dp.end()) {
        return dp[n];
    }

    ll ans = INF;

    vector<ll> muls = {2, 3, 5};
    vector<ll> costs = {A, B, C};
    for (int i = 0; i < (int) muls.size(); i++) {
        const ll mul = muls[i];
        {
            const ll next = n / mul;
            if (next == 0) continue;
            ll cand = 0;
            cand += D * (abs(next * mul - n));
            cand += costs[i];
            cand += do_solve(dp, next, A, B, C, D);
            chmin(ans, cand);
        }
        {
            ll next = (n + mul - 1) / mul;
            ll cand = 0;
            cand += D * (abs(next * mul - n));
            cand += costs[i];
            cand += do_solve(dp, next, A, B, C, D);
            chmin(ans, cand);
        }
    }

    /*
     *  Two ways to judge whether applying D by n times.
     */

    // (1) When n > 2 * MAX_COST, it is always better to apply x2, x3, or x5 even if D == 1 and A, B, C == 10 ^ 9.
    // if (n <= 2 * MAX_COST) {
    //     chmin(ans, n * D);
    // }
    // (2) `ans` must be less than INF, so skip it if n * D > INF
    if (n <= INF / D) {
        chmin(ans, n * D);
    }

    dp[n] = ans;
    return ans;
}

ll solve(const ll N, const ll A, const ll B, const ll C, const ll D) {
    map<ll, ll> dp;
    dp[0] = 0;
    dp[1] = D;
    return do_solve(dp, N, A, B, C, D);
}

int main(void) {
    int T;
    cin >> T;

    while (T-- > 0) {
        ll N, A, B, C, D;
        cin >> N >> A >> B >> C >> D;

        cout << solve(N, A, B, C, D) << endl;
    }

    return 0;
}
