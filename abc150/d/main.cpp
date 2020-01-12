#include <algorithm>
#include <iostream>
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

ll gcd(const ll sx, const ll sy) {
    ll x = min(sx, sy);
    ll y = max(sx, sy);
    ll tmp;
    while (x > 0) {
        tmp = y;
        y = x;
        x = tmp % x;
    }
    return y;
}

ll lcm(const ll x, const ll y) {
    return x / gcd(x, y) * y;
}

int calc_two_count(ll x) {
    int count = 0;
    while (x > 0 && x % 2 == 0) {
        x /= 2;
        count++;
    }
    return count;
}

vector<ll> a;

int main(void) {
    ll N, M;
    cin >> N >> M;

    a.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        if (a[i] % 2 != 0) {
            cout << "0" << endl;
            return 0;
        }
    }

    ll two_count = calc_two_count(a[0]);
    a[0] >>= two_count;
    for (int i = 1; i < N; i++) {
        if (calc_two_count(a[i]) != two_count) {
            cout << "0" << endl;
            return 0;
        }
        a[i] >>= two_count;
    }

    ll l = 1;
    for (int i = 0; i < N; i++) {
        l = lcm(l, a[i]);
        if (l > M) {
            cout << "0" << endl;
            return 0;
        }
    }

    // cout << l << endl;

    ll x = l << (two_count - 1);
    ll ans = 0;
    while (x <= M) {
        ans++;
        x += 2 * (l << (two_count - 1));
    }

    cout << ans << endl;

    return 0;
}
