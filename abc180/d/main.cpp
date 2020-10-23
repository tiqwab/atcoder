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
    ll X, Y, A, B;
    cin >> X >> Y >> A >> B;

    ll ans = 0;
    ll cur = X;
    while (cur < Y / A && (cur * A) < (cur + B)) {
        cur = cur * A;
        ans++;
    }
    ans += max(0LL, (Y - cur - 1) / B);

    cout << ans << endl;
    return 0;
}
