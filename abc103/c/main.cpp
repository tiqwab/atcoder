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

ll gcd(const ll sx, const ll sy) {
    ll x = min(sx, sy);
    ll y = max(sx, sy);
    ll tmp;
    while (x > 0) {
        tmp = y;
        y = x;
        x = tmp % x;
    }
    return y;
}

ll lcm(const ll x, const ll y) {
    return x / gcd(x, y) * y;
}

int N;
vector<ll> as;

int main(void) {
    cin >> N;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    // ll m = 1LL;
    // for (int i = 0; i < N; i++) {
    //     m = lcm(m, as[i]);
    // }
    // cout << m << endl;

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += as[i] - 1;
    }

    cout << ans << endl;

    return 0;
}
