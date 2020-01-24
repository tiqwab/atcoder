#include <algorithm>
#include <iostream>
#include <vector>

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
    ll W, H, x, y;
    cin >> W >> H >> x >> y;

    double area = (W * H) / 2.0;
    // double area = (W * H) / 2.0f; // this is calculated as float then converted into double

    if (x * 2 == W && y * 2 == H) {
        printf("%.10f %d\n", area, 1);
    } else {
        printf("%.10f %d\n", area, 0);
    }

    return 0;
}
