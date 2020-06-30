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

// O(N * logN)
int main(void) {
    int N;
    cin >> N;

    ll ans = 0;
    ll cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            ans += j;
            cnt++;
        }
    }

    // printf("ans: %lld, cnt: %lld\n", ans, cnt);
    cout << ans << endl;

    return 0;
}
