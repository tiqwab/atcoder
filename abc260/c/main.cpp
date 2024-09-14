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
    ll X, Y;
    cin >> N >> X >> Y;

    ll acc_r = 1;
    ll acc_b = 0;

    for (int i = 0; i < N - 1; i++) {
        ll next_r = 0;
        ll next_b = 0;
        next_r += acc_r;
        acc_b += acc_r * X;
        next_r += acc_b;
        next_b += acc_b * Y;

        acc_r = next_r;
        acc_b = next_b;
    }

    printf("%lld\n", acc_b);

    return 0;
}
