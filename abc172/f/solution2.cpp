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

vector<ll> as;

ll solve(ll X, ll S) {
    ll D = (S - X) / 2; // = a & b

    ll cand = D;
    for (int bit = 41; bit >= 0; bit--) {
        ll x = X & (1LL << bit);
        if (x == 0) continue;
        if ((cand | x) <= as[0]) {
            cand |= x;
        }
    }

    // check answer
    ll a = cand;
    ll b = S - cand;
    // printf("a: %lld, b: %lld\n", a, b);
    if (a > as[0]) {
        return -1;
    }
    if (b < 0) {
        return -1;
    }
    if ((a ^ b) != X) {
        return -1;
    }

    return cand;
}

// ref. https://img.atcoder.jp/abc172/editorial.pdf
int main(void) {
    int N;
    cin >> N;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    ll X = 0;
    for (int i = 2; i < N; i++) {
        X ^= as[i];
    }

    ll S = as[0] + as[1];

    ll ans = solve(X, S);

    if (ans <= 0) {
        cout << -1 << endl;
    } else {
        cout << as[0] - ans << endl;
    }

    return 0;
}
