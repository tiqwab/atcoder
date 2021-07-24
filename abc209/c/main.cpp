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

const ll MOD = 1000 * 1000 * 1000 + 7;

int main(void) {
    int N;
    cin >> N;

    vector<ll> cs(N);
    for (int i = 0; i < N; i++) {
        cin >> cs[i];
    }
    sort(cs.begin(), cs.end());

    ll ans = 1;
    for (int i = 0; i < N; i++) {
        ans = (ans * (cs[i] - i)) % MOD;
    }
    cout << ans << endl;

    return 0;
}
