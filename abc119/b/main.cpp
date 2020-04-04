#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
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
    int N;
    cin >> N;

    const double BTC = 380000.0;
    double ans = 0;
    for (int i = 0; i < N; i++) {
        double x;
        string u;
        cin >> x >> u;

        if (u == "JPY") {
            ans += x;
        } else {
            ans += x * BTC;
        }
    }

    printf("%.6f\n", ans);

    return 0;
}
