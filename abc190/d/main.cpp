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
    ll N;
    cin >> N;

    if (N == 1) {
        cout << 2 << endl;
        return 0;
    }

    ll n = 0;
    for (; n * n <= 2 * N; n++) {
    }
    // n += 1;

    ll ans = 0;

    for (ll l = 1; l < n; l++) {
        if (l % 2 == 0) {
            if (N % l == 0) {
                continue;
            }
            ll a = (N / l) + (N / l + 1LL);
            a = a * (l / 2);
            if (a == N) {
                if (((N / l) - l / 2 + 1) == 0) {
                    // fprintf(stderr, "%lld, += 1\n", l);
                    ans += 1;
                } else {
                    // fprintf(stderr, "%lld, += 2\n", l);
                    ans += 2;
                }
            }
        } else {
            if (N % l == 0) {
                if (N / l - (l - 1) / 2 == 0) {
                    // fprintf(stderr, "%lld, += 1\n", l);
                    ans += 1;
                } else {
                    // fprintf(stderr, "%lld, += 2\n", l);
                    ans += 2;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
