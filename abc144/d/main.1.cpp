/*
 * Soltuion 1 in https://img.atcoder.jp/abc144/editorial.pdf 
 */

#include <iostream>
#include <cmath>

using namespace std;

double calc_water_volume(double a, double b, double theta) {
    if (tan(theta) < b / a) {
        return (a * (a * b - (a * a * tan(theta)) / 2.0));
    } else {
        return ((a * b * b / tan(theta)) / 2.0);
    }
}

int main(void) {
    double a, b, x;

    cin >> a >> b >> x;

    double left = 0.0, right = 90.0, mid;
    while (right - left > 0.000001) {
        mid = (left + right) / 2.0;
        double theta = mid * M_PI / 180.0;
        double v = calc_water_volume(a, b, theta);
        if (v < x) {
            right = mid;
        } else {
            left = mid;
        }
    }

    printf("%3.7f\n", left);

    return 0;
}
