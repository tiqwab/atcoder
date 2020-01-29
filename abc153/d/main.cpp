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

ll twos[64];

int main(void) {
    ll H;
    cin >> H;

    twos[0] = 1;
    for (int i = 1; i < 64; i++) {
        twos[i] = twos[i - 1] * 2;
    }
    if (H == 1) {
        cout << "1" << endl;
        return 0;
    }

    H = H & ~(0x1);
    // printf("%lld\n", H);
    // printf("%lld\n", twos[62]);
    // printf("%lld\n", twos[63]);

    ll acc = 0;
    for (int i = 0; i < 64; i++) {
        // printf("%lld\n", twos[i]);
        if (twos[i] > H) break;
        acc += twos[i];
    }

    cout << acc << endl;

    return 0;
}
