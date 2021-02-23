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

ll MAX_M = 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL;

bool f(const ll mid, const string X, const ll M) {
    ll acc = 0;
    for (int i = 0; i < (int) X.size(); i++) {
        ll y = (ll) (X[i] - '0');
        if (acc > (MAX_M - y) / mid) {
            return false;
        }
        acc = acc * mid + y;
    }
    // printf("%lld\n", acc);
    return acc <= M;
}

ll solve(const string X, const ll M) {
    ll l = 0;
    ll r = MAX_M * 2;
    ll d = 0;

    for (auto x : X) {
        chmax(d, (ll) (x - '0'));
    }

    while (r - l > 1) {
        ll mid = l + (r - l) / 2;
        // printf("%lld, %lld, %lld\n", l, r, mid);
        if (f(mid, X, M)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    return max(0LL, l - d);
}

int main(void) {
    string X;
    cin >> X;
    ll M;
    cin >> M;

    if (((int) X.size()) == 1) {
        if (stoi(X) <= M) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
        return 0;
    }

    cout << solve(X, M) << endl;

    return 0;
}
