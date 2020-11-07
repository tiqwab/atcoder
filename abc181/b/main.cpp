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
    int N;
    cin >> N;

    ll ans = 0LL;
    for (int i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;

        ans += b * (b + 1) / 2 - (a - 1) * a / 2;
    }

    cout << ans << endl;

    return 0;
}
