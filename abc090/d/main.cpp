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
    ll N, K;
    cin >> N >> K;

    ll ans = 0;
    for (ll b = K + 1; b <= N; b++) {
        ll x = N / b;
        // ll y = max(0LL, ((N % b) - K));
        ll y = max(0LL, (N % b) - max(0LL, (K - 1)));
        ll z = x * (b - K);
        // printf("b: %lld, x: %lld, y: %lld, z: %lld\n", b, x, y, z);
        ans += y;
        ans += z;
    }

    cout << ans << endl;

    return 0;
}
