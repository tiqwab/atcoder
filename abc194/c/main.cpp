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

    map<ll, ll> counter;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        counter[a]++;
    }

    ll ans = 0;
    for (ll i = -200; i <= 200; i++) {
        for (ll j = -200; j <= 200; j++) {
            if (i != j && counter.find(i) != counter.end() && counter.find(j) != counter.end()) {
                ll v_a = i;
                ll cnt_a = counter[i];
                ll v_b = j;
                ll cnt_b = counter[j];
                ans += (v_a - v_b) * (v_a - v_b) * cnt_a * cnt_b;
            }
        }
    }
    assert(ans % 2 == 0);
    ans /= 2;
    cout << ans << endl;

    return 0;
}
