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
    ll n;
    cin >> n;

    auto f = [](const ll x) {
        return x * (x + 1) / 2;
    };

    ll longest = n + 1;

    ll left = 1LL;
    ll right = ll(2e9);
    while (right - left > 1) {
        ll mid = left + (right - left) / 2;
        if (f(mid) > longest) {
            right = mid;
        } else {
            left = mid;
        }
    }

    ll ans = max(n - left + 1, 1LL);
    cout << ans << endl;

    return 0;
}
