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

ll calc_mod(const ll base, const ll mod, const ll n) {
    if (n == 0) {
        return 1;
    }
    ll ans = calc_mod(base, mod, n / 2);
    ans = (ans * ans) % mod;
    if (n % 2 == 1) {
        ans = (ans * (base % mod)) % mod;
    }
    return ans;
}

int main(void) {
    ll N, K, M;
    cin >> N >> K >> M;

    const ll MOD = 998244353LL;

    if (M % MOD == 0) {
        printf("0\n");
        return 0;
    }

    ll b = calc_mod(K, MOD - 1, N);
    printf("%lld\n", calc_mod(M, MOD, b));

    return 0;
}
