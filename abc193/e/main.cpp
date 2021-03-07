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

/*
 * Return gcd(x, y).
 * x and y store values satisfying `ax + by = gcd(a, b)`
 * ref. https://qiita.com/drken/items/b97ff231e43bce50199a 
 */
// ll ext_gcd(ll a, ll b, ll *x, ll *y) {
//     if (b == 0) {
//         *x = 1;
//         *y = 0;
//         return a;
//     }
//     ll d = ext_gcd(b, a % b, y, x);
//     *y = (*y) - a / b * (*x);
//     return d;
// }

ll safe_mod(ll x, ll m) {
    x %= m;
    if (x < 0) {
        x += m;
    }
    return x;
}

// @param b `1 <= b`
// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x < b/g
pair<ll, ll> inv_gcd(ll a, ll b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};

    // Contracts:
    // [1] s - m0 * a = 0 (mod b)
    // [2] t - m1 * a = 0 (mod b)
    // [3] s * |m1| + t * |m0| <= b
    long long s = b, t = a;
    long long m0 = 0, m1 = 1;

    while (t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b

        // [3]:
        // (s - t * u) * |m1| + t * |m0 - m1 * u|
        // <= s * |m1| - t * u * |m1| + t * (|m0| + |m1| * u)
        // = s * |m1| + t * |m0| <= b

        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    // by [3]: |m0| <= b/g
    // by g != b: |m0| < b/g
    if (m0 < 0) m0 += b / s;
    return {s, m0};
}
// ref. https://github.com/atcoder/ac-library/blob/c36e178c126110d319b7781d1e875bc6faed36a2/atcoder/math.hpp#L34
// calculate (rem, mod) which satisfies:
//   rem % m[0] == r[0] and rem % m[1] == r[1] and ...
pair<ll, ll> crt(const vector<ll>& r, const vector<ll>& m) {
    assert(r.size() == m.size());
    int n = int(r.size());
    // Contracts: 0 <= r0 < m0
    long long r0 = 0, m0 = 1;
    for (int i = 0; i < n; i++) {
        assert(1 <= m[i]);
        long long r1 = safe_mod(r[i], m[i]), m1 = m[i];
        if (m0 < m1) {
            std::swap(r0, r1);
            std::swap(m0, m1);
        }
        if (m0 % m1 == 0) {
            if (r0 % m1 != r1) return make_pair(0, 0);
            continue;
        }
        // assume: m0 > m1, lcm(m0, m1) >= 2 * max(m0, m1)

        // (r0, m0), (r1, m1) -> (r2, m2 = lcm(m0, m1));
        // r2 % m0 = r0
        // r2 % m1 = r1
        // -> (r0 + x*m0) % m1 = r1
        // -> x*u0*g = r1-r0 (mod u1*g) (u0*g = m0, u1*g = m1)
        // -> x = (r1 - r0) / g * inv(u0) (mod u1)

        // im = inv(u0) (mod u1) (0 <= im < u1)
        long long g, im;
        std::tie(g, im) = inv_gcd(m0, m1);

        long long u1 = (m1 / g);
        // |r1 - r0| < (m0 + m1) <= lcm(m0, m1)
        if ((r1 - r0) % g) return {0, 0};

        // u1 * u1 <= m1 * m1 / g / g <= m0 * m1 / g = lcm(m0, m1)
        long long x = (r1 - r0) / g % u1 * im % u1;

        // |r0| + |m0 * x|
        // < m0 + m0 * (u1 - 1)
        // = m0 + m0 * m1 / g - m0
        // = lcm(m0, m1)
        r0 += x * m0;
        m0 *= u1;  // -> lcm(m0, m1)
        if (r0 < 0) r0 += m0;
    }
    return make_pair(r0, m0);
}

const ll INF = LONG_LONG_MAX / 2;

// AtCoder ABC 193 E
int main(void) {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        ll X, Y, P, Q;
        cin >> X >> Y >> P >> Q;

        ll ans = INF;

        for (ll t1 = X; t1 < X + Y; t1++) {
            for (ll t2 = P; t2 < P + Q; t2++) {
                ll t, lcm;
                tie(t, lcm) = crt({t1, t2}, {(X + Y) * 2, P + Q});
                if (lcm == 0) {
                    continue;
                }
                if (ans > t) {
                    ans = t;
                }
            }
        }

        if (ans == INF) {
            cout << "infinity" << endl;
        } else {
            cout << ans << endl;
        }
    }

    return 0;
}
