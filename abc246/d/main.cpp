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

const ll MAX_V = 1000000;

ll calc(ll a, ll b) {
    return a * a * a + a * a * b + a * b * b + b * b * b;
}

ll check(const ll a, const ll N) {
    ll left = -1;
    ll right = MAX_V;
    while (right - left > 1) {
        ll mid = left + (right - left) / 2;
        if (calc(a, mid) >= N) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return calc(a, right);
}

int main(void) {
    ll N;
    cin >> N;

    ll cand_v = LONG_LONG_MAX / 2;

    for (ll i = 0; i <= MAX_V; i++) {
        chmin(cand_v, check(i, N));
    }

    printf("%lld\n", cand_v);

    return 0;
}
