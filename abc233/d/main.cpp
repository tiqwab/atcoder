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
    int N;
    cin >> N;
    ll K;
    cin >> K;
    vector<ll> as;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        as.push_back(a);
    }

    map<ll, int> memo;
    ll acc = 0;
    ll ans = 0;
    memo[0] = 1;
    for (int i = 0; i < N; i++) {
        acc += as[i];
        if (memo.find(acc - K) != memo.end()) {
            ans += memo[acc - K];
        }
        memo[acc]++;
    }

    printf("%lld\n", ans);
    return 0;
}
