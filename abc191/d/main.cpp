#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>
#include <math.h>

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
    double X, Y, R;
    cin >> X >> Y >> R;

    if (X < 0) {
        X *= -1;
    }
    if (Y < 0) {
        Y *= -1;
    }

    // R が小さすぎて該当する y がない場合


    ll ans = 0;

    for (ll x = (ll) floor(X - R); x <= (ll) (X + R); x++) {
        if (ceil(Y) != ceil(Y + R)){
            ll left = (ll) ceil(Y);
            ll right = (ll) ceil(Y + R + 1);
            while (right - left > 1) {
                ll mid = left + (right - left) / 2;
                if ((double) mid * mid <= R * R - (double) x * x) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            ans += right - ((ll) floor(Y));
        }

        // TODO for points (y < Y)
    }






    // bool is_y_int = false;
    // if (floor(Y) == ceil(Y)) {
    //     is_y_int = true;
    // }

    // bool is_x_int = false;
    // if (floor(X) == ceil(X)) {
    //     is_x_int = true;
    // }

    return 0;
}
