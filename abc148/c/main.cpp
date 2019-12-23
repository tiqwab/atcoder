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

ll calc_gcd(ll x, ll y) {
    if (x == 0) {
        return y;
    }
    return calc_gcd(y % x, x);
}

int main(void) {
    ll A, B;
    cin >> A >> B;

    ll gcd;
    if (A < B) {
        gcd = calc_gcd(A, B);
    } else {
        gcd = calc_gcd(B, A);
    }

    cout << A * B / gcd << endl;

    return 0;
}
