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
    int X, Y, Z;
    cin >> X >> Y >> Z;

    int l = 0;
    int r = 10000000;

    auto f = [](const ll x, const ll y, const ll z, const ll n) {
        return y * z > x * n;
    };

    while (r - l > 1) {
        int mid = l + (r - l) / 2;
        if (f(X, Y, Z, mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << l << endl;

    return 0;
}
