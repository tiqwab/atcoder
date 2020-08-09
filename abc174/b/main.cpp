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
    ll D;
    cin >> N >> D;

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        if (x * x + y * y <= D * D) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
