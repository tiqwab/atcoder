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

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

ll gcd_ext(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    ll ans = gcd_ext(b, a % b, x, y);
    ll _x = x;
    ll _y = y;
    x = _y;
    y = _x - a / b * _y;

    return ans;
}

ll solve(ll N, ll S, ll K) {
    ll g = gcd(K, N);

    if (S % g != 0) {
        return -1;
    }

    N /= g;
    S /= g;
    K /= g;

    ll x, y;
    gcd_ext(K, N, x, y);
    return (((x * -1 * S) % N) + N) % N;
}

// ref. https://drken1215.hatenablog.com/entry/2020/12/20/015100
int main(void) {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        ll N, S, K;
        cin >> N >> S >> K;
        cout << solve(N, S, K) << endl;
    }
    return 0;
}
