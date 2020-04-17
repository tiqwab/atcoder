#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

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

int main(void) {
    int K;
    cin >> K;

    ll ans = 0;
    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= K; j++) {
            for (int k = 1; k <= K; k++) {
                ans += gcd(i, gcd(j, k));
            }
        }
    }

    cout << ans << endl;

    return 0;
}
