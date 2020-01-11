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

ll calc(const ll A, const ll B, const ll m) {
    if (m > B) return 0LL;
    ll x = A % m;
    ll y = x == 0 ? A : A + m - x;
    return (B - y) / m + 1;
}

int main(void) {
    ll A, B, C, D;
    cin >> A >> B >> C >> D;

    if (D < C) {
        swap(C, D);
    }

    ll g1 = calc(A, B, C);
    ll g2 = calc(A, B, D);
    ll g3 = calc(A, B, lcm(C, D));

    // printf("%lld, %lld, %lld\n", g1, g2, g3);

    ll dividable = g1 + g2 - g3;
    cout << (B - A + 1) - dividable << endl;

    return 0;
}
