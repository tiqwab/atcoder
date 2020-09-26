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

ll INF = LONG_LONG_MAX / 2;

int main(void) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll ans = -INF;
    chmax(ans, a * c);
    chmax(ans, a * d);
    chmax(ans, b * c);
    chmax(ans, b * d);
    cout << ans << endl;
    return 0;
}
