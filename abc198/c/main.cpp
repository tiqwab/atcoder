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
    ll R, X, Y;
    cin >> R >> X >> Y;

    ll dist = X * X + Y * Y;

    for (ll i = 0; i <= 1000LL * 1000LL; i++) {
        ll l = R * R * i * i;
        ll r = R * R * (i + 1) * (i + 1);
        if (l < dist && dist <= r) {
            if (i == 0 && dist < r) {
                cout << 2 << endl;
            } else {
                cout << i + 1 << endl;
            }
            return 0;
        }
    }

    return 0;
}
