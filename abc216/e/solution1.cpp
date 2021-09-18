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

int main(void) {
    int N, K;
    cin >> N >> K;

    map<ll, ll> m;

    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        m[a]++;
    }
    m[0]++;

    int k = K;
    ll ans = 0;

    while (k > 0 && m.size() > 1) {
        auto it = m.rbegin();
        pair<ll, ll> cur = *it;
        it++;
        pair<ll, ll> prev = *it;

        if ((cur.first - prev.first) * cur.second <= k) {
            ll a = cur.first;
            ll b = prev.first + 1;
            ans += cur.second * ((a + b) * (a - b + 1) / 2);

            k -= cur.second * (cur.first - prev.first);

            m.erase(m.find(cur.first));
            m[prev.first] += cur.second;
        } else {
            int n = k / cur.second;
            ll a = cur.first;
            ll b = a - n + 1;
            ans += cur.second * ((a + b) * n / 2);
            ans += (b - 1) * (k % cur.second);

            k = 0;
        }
    }

    cout << ans << endl;

    return 0;
}
