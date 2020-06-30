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

// O(N^(1/2))
// ref. https://maspypy.com/atcoder-%E5%8F%82%E5%8A%A0%E6%84%9F%E6%83%B3-2020-06-27abc-172#toc4
int main(void) {
    int N;
    cin >> N;

    auto f = [](const ll n) {
        return n * (n + 1) / 2;
    };

    ll ans = 0;
    for (int i = 1; i * i <= N; i++) {
        // x == y
        ans += i * i;

        // x < y or x > y
        ans += 2 * i * (f(N / i) - f(i));
    }

    cout << ans << endl;

    return 0;
}
