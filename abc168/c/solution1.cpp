#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <math.h>
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
    double A, B;
    int H, M;
    cin >> A >> B >> H >> M;

    double minutes = H * 60 + M;

    double ta = M_PI / 30 * minutes;
    double tb = M_PI / (30 * 12) * minutes;

    printf("%.10f\n", sqrt(A * A + B * B - 2 * A * B * cos(ta - tb)));

    return 0;
}
