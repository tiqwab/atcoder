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
    int N, Q;
    cin >> N >> Q;

    vector<ll> as;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        as.push_back(a);
    }
    sort(as.begin(), as.end());

    vector<ll> acc(N + 1);
    for (int i = 0; i < N; i++) {
        acc[i + 1] = acc[i] + as[i];
    }

    for (int i = 0; i < Q; i++) {
        ll x;
        cin >> x;
        auto it = lower_bound(as.begin(), as.end(), x);
        int idx = distance(as.begin(), it);
        printf("%lld\n", (idx * x - acc[idx]) + ((acc[N] - acc[idx]) - (N - idx) * x));
    }

    return 0;
}
