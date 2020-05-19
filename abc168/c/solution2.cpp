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
    const double PI = acos(-1.0);

    double ta = 2 * PI / 60 * minutes; // choshin
    double tb = 2 * PI / (60 * 12) * minutes; // tanshin

    double ax = A * sin(ta);
    double ay = A * cos(ta);
    double bx = B * sin(tb);
    double by = B * cos(tb);

    printf("%.10f\n", sqrt(pow((ax - bx), 2) + pow((ay - by), 2)));

    return 0;
}
