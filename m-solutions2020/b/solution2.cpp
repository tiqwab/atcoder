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

int pow(int base, int n) {
    if (n == 0) {
        return 1;
    } else {
        return base * (pow(base, n-1));
    }
}

int main(void) {
    int A, B, C, K;
    cin >> A >> B >> C >> K;

    const int mx = pow(3, K);
    bool ok = false;

    for (int bits = 0; bits < mx; bits++) {
        int cur = bits;
        int a = 0, b = 0, c = 0;
        for (int trial = 0; trial < K; trial++) {
            switch (cur % 3) {
                case 0:
                    a++;
                    break;
                case 1:
                    b++;
                    break;
                case 2:
                    c++;
                    break;
                default:
                    break;
            }
            cur /= 3;
        }
        int res_a = A * pow(2, a);
        int res_b = B * pow(2, b);
        int res_c = C * pow(2, c);
        if (res_a < res_b && res_b < res_c) {
            ok = true;
            break;
        }
    }

    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
