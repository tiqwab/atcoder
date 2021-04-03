#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>
#include <math.h>

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
    cin >> N;

    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    double center_x, center_y;
    center_x = (x1 + x2) / 2.0;
    center_y = (y1 + y2) / 2.0;

    double angle = 360.0 / double(N);
    double theta = angle / 360.0 * 2 * M_PI;

    double tmp_x = x1 - center_x;
    double tmp_y = y1 - center_y;
    double ans_x = tmp_x * cos(theta) - tmp_y * sin(theta) + center_x;
    double ans_y = tmp_x * sin(theta) + tmp_y * cos(theta) + center_y;

    printf("%.6f %.6f\n", ans_x, ans_y);

    return 0;
}
