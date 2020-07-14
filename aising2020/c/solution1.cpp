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

ll solve(const ll n) {
    ll ans = 0;

    for (ll a = 1; a <= n; a++) {
        ll x = a * a;
        if (x > n) {
            break;
        }
        for (ll b = 1; b <= n; b++) {
            ll y = b * b + a * b;
            if (x + y > n) {
                break;
            }
            for (ll c = 1; c <= n; c++) {
                ll z = c * c + b * c + c * a;

                if (z > n) {
                    break;
                }

                if (x + y + z == n) {
                    ans++;
                }
            }
        }
    }

    return ans;
}

int main(void) {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        printf("%lld\n", solve(i));
        // solve(i);
    }

    return 0;
}
