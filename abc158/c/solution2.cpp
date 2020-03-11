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

int round_up(int x, int base) {
    return (x + base - 1) / base;
}

int round_down(int x, int base) {
    return x / base;
}

int main(void) {
    int A, B;
    cin >> A >> B;

    int low_a = round_up(100 * A, 8);
    int high_a = round_up(100 * (A + 1), 8) - 1;

    int low_b = round_up(100 * B, 10);
    int high_b = round_up(100 * (B + 1), 10) - 1;

    if (high_a < low_b || high_b < low_a) {
        cout << -1 << endl;
    } else {
        cout << max(low_a, low_b) << endl;
    }

    return 0;
}
