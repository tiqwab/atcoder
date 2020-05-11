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
    ll A, B, C, K;
    cin >> A >> B >> C >> K;

    ll cnt = K;

    // A
    ll ans = min(A, cnt);
    cnt -= min(A, cnt);

    // B
    cnt = max(0LL, cnt - B);

    // C
    ans -= cnt;

    cout << ans << endl;

    return 0;
}
