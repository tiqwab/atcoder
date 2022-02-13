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

const ll BORDER = 1000 * 1000 * 100;

int main(void) {
    ll N;
    cin >> N;

    ll ans = 0;
    ll n = N;

    for (ll i = 1; i <= 10000; i++) {
        if (n <= BORDER) {
            break;
        }
        ll nn = N / (i + 1);
        ans += (n - nn) * i;
#ifdef DEBUG
        printf("ans += (%lld - %lld) * %lld\n", n, nn, i);
#endif
        n = nn;
    }

    for (ll i = 1; i <= n; i++) {
        ans += N / i;
    }

    printf("%lld\n", ans);
    return 0;
}
