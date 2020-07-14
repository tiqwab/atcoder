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

int f(const int d, const int n) {
    return n / d;
}

int main(void) {
    int L, R, d;
    cin >> L >> R >> d;

    cout << f(d, R) - f(d, L - 1) << endl;

    return 0;
}
