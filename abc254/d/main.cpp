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
    ll N;
    cin >> N;

    vector<ll> xs(N + 1);

    for (ll i = 1; i * i <= N; i++) {
        for (ll j = 1; j <= N; j++) {
            if (j % (i * i) == 0) {
                xs[j] = j / (i * i);
            }
        }
    }

    map<int, int> counter;
    for (int i = 1; i <= N; i++) {
        counter[xs[i]] += 1;
    }

    ll ans = 0;
    for (auto &p : counter) {
        ans += p.second * p.second;
    }

    printf("%lld\n", ans);

    return 0;
}
