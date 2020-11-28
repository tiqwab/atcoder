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
    double sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;

    double a = (-1 * gy - sy) / (gx - sx);
    double b = sy - a * sx;

    double ans = -1 * (b / a);
    printf("%.7f\n", ans);

    return 0;
}
