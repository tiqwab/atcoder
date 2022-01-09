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
    ll N;
    cin >> N;

    ll ans = 0;

    for (ll a = 1; a * a * a <= N; a++) {
        for (ll b = a; a * b * b <= N; b++) {
            // printf("a: %lld, b: %lld, += %lld\n", a, b, N / (a * b) - b + 1);
            ans += N / (a * b) - b + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
