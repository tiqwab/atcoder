#include <algorithm>
#include <cassert>
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

ll gcd(const ll a, const ll b) {
    assert(a <= b);
    if (a == 0) return b;
    return gcd(b % a, a);
}

ll lcm(const ll a, const ll b) {
    assert(a <= b);
    return a * b / gcd(a, b);
}

ll calc(const ll x, const ll m) {
    return x / m;
}

int main(void) {
    ll A, B, C, D;
    cin >> A >> B >> C >> D;

    if (D < C) {
        swap(C, D);
    }

    ll l = lcm(C, D);

    ll g1 = calc(A - 1, C);
    ll g2 = calc(A - 1, D);
    ll g3 = calc(A - 1, l);
    
    ll g4 = calc(B, C);
    ll g5 = calc(B, D);
    ll g6 = calc(B, l);

    ll dividable = ((g4 + g5 - g6) - (g1 + g2 - g3));
    cout << ((B - A + 1) - dividable) << endl;
    return 0;
}
