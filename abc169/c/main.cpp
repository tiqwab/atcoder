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
    ll A, B, C;
    char c;
    cin >> A >> B >> c >> C;
    // printf("%lld, %lld, %lld\n", A, B, C);

    ll x = A * (B * 100 + C);
    // printf("%lld\n", x);
    x = x / 100;
    cout << x << endl;

    return 0;
}
