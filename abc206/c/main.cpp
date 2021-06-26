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

    map<int, ll> counter;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        counter[a]++;
    }

    ll ans = 0;

    for (auto p : counter) {
        ll cnt = p.second;
        ans += cnt * (N - cnt);
    }

    ans /= 2;

    cout << ans << endl;

    return 0;
}
