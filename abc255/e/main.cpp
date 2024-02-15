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
    int N, M;
    cin >> N >> M;

    vector<ll> ss;
    for (int i = 0; i < N - 1; i++) {
        ll s;
        cin >> s;
        ss.push_back(s);
    }

    vector<ll> xs;
    for (int i = 0; i < M; i++) {
        ll x;
        cin >> x;
        xs.push_back(x);
    }

    map<ll, int> counter;

    for (auto x : xs) {
        counter[x]++;
    }

    // a = m + nx
    ll m = 0;
    ll n = 1;

    for (int i = 0; i < N - 1; i++) {
        const ll s = ss[i];
        m = s - m;
        n *= -1;
        for (auto x : xs) {
            counter[(x - m) * n]++;
        }
    }

    int ans = 0;
    for (auto p : counter) {
        chmax(ans, p.second);
    }
    printf("%d\n", ans);

    return 0;
}
