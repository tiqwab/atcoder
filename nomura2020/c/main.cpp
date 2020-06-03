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

// as[i]: the number of nodes which is at the level i and is leaf
vector<int> as;
// bs[i]: the maximum number of nodes which is at the level i and is not leaf
vector<ll> bs;

ll solve(const int N) {
    ll ans = 0;

    ll cur_vs = 0;
    for (int cur_l = N; cur_l > 0; cur_l--) {
        const ll next_max = bs[cur_l - 1];

        cur_vs += as[cur_l];
        ans += cur_vs;
        // printf("cur_l: %d, next_max: %d, cur_vs: %d, ans: %lld\n", cur_l, next_max, cur_vs, ans);
        if (cur_vs > next_max) {
            if (cur_vs > 2 * next_max) {
                return -1;
            }
            cur_vs = next_max;
        }
    }

    ans += 1;
    return ans;
}

int main(void) {
    int N;
    cin >> N;

    as.resize(N + 1);
    for (int i = 0; i <= N; i++) {
        cin >> as[i];
    }

    if (N == 0) {
        if (as[0] == 1) {
            cout << 1 << endl;
        } else {
            cout << -1 << endl;
        }
        return 0;
    }

    bs.resize(N + 1);
    bs[0] = 1 - as[0];
    bs[N] = 0;
    for (int i = 1; i < N; i++) {
        bs[i] = min(LONG_LONG_MAX / 2, bs[i - 1] * 2 - as[i]);
    }
    for (int i = 0; i < N; i++) {
        // printf("bs[%d]: %lld\n", i, bs[i]);
        if (bs[i] <= 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << solve(N) << endl;

    return 0;
}
