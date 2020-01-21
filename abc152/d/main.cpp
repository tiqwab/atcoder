#include <algorithm>
#include <iostream>
#include <map>
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

map<pair<ll, ll>, ll> m;

ll solve(const ll N) {
    for (int i = 1; i <= N; i++) {
        ll x = i % 10;
        ll y = i;
        while (y >= 100) {
            y /= 10;
        }
        if (y == 10) {
            y = 1;
        } else if (y > 10) {
            y /= 10;
        }

        m[make_pair(y, x)]++;
    }

    ll count = 0;
    for (auto &p1 : m) {
        ll ay = p1.first.first;
        ll ax = p1.first.second;
        ll acount = p1.second;
        // printf("(%lld, %lld): %lld\n", ay, ax, acount);

        if (ax == ay) {
            // printf("plus: %lld\n", acount * acount);
            count += acount * acount;
        } else {
            ll bcount = m[make_pair(ax, ay)];
            count += acount * bcount;
            // printf("plus: %lld\n", acount * bcount);
        }
    }

    return count;
}

int main(void) {
    ll N;
    cin >> N;

    cout << solve(N) << endl;

    return 0;
}
