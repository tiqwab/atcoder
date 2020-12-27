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

int main(void) {
    ll N;
    cin >> N;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }
    sort(as.begin(), as.end());

    ll ans = 0;
    for (ll i = 0; i < N - 1; i++) {
        const ll l = as[i];
        const ll r = as[i + 1];
        ans += (i + 1) * (N - (i + 1)) * (r - l);
    }
    cout << ans << endl;

    return 0;
}
