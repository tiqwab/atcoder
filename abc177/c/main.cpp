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

const ll MOD = 1000000007LL;

vector<ll> as;

vector<ll> ss;

int main(void) {
    int N;
    cin >> N;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    ss.resize(N + 1, 0);
    for (int i = 0; i < N; i++) {
        ss[i + 1] = (ss[i] + as[i]) % MOD;
    }

    ll ans = 0;
    for (int i = N - 1; i >= 0; i--) {
        ll x = as[i];
        // printf("%lld * %lld\n", x, ss[i]);
        x = (x * ss[i]) % MOD;
        ans = (ans + x) % MOD;
    }

    cout << ans << endl;

    return 0;
}
