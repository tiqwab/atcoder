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

map<ll, ll> counter;

const ll MOD = 2019;

int main(void) {
    string S;
    cin >> S;

    counter[0]++;
    ll ans = 0;
    ll acc = 0;
    ll power = 1;
    for (int i = (int) S.size() - 1; i >= 0; i--) {
        acc = (((power * (S[i] - '0')) % MOD) + acc) % MOD;
        power = (power * 10) % MOD;

        // printf("acc: %lld\n", acc);
        ans += counter[acc];
        counter[acc]++;
    }

    cout << ans << endl;

    return 0;
}
