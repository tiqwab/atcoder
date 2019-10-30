#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    double a, b, x, h;

    cin >> a >> b >> x;

    h = x / (a * a);

    double radian;
    if (h > b / 2) {
        double v = a / (2 * (b - h));
        radian = atan(v);
    } else {
        // double v = (2 * h + a - b) / b;
        double v = (2 * a * h) / (b * b);
        radian = atan(v);
    }

    // cout << radian << endl;
    fprintf(stdout, "%2.7f\n", 90 - radian * 180 / M_PI);
    // cout << 90 - radian * 180 / M_PI << endl;

    return 0;
}
