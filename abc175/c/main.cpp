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
    ll X, K, D;
    cin >> X >> K >> D;

    if (X < 0) {
        X = abs(X);
    }

    if (K >= X / D) {
        // printf("[1]: %lld or %lld\n", X % D, D - (X % D));
        int step = (X - X % D) / D;
        if (step % 2 == K % 2) {
            cout << X % D << endl;
        } else {
            cout << D - (X % D) << endl;
        }
    } else {
        // printf("[2]: %lld\n", X - K * D);
        cout << X - K * D << endl;
    }

    return 0;
}
