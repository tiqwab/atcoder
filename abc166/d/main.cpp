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
    ll X;
    cin >> X;

    vector<ll> origs;
    vector<ll> elems;
    ll x = 1;
    origs.push_back(0);
    elems.push_back(0);
    origs.push_back(1);
    elems.push_back(1);
    ll prev = 1;
    while (1) {
        x += 1;
        ll pows = x * x * x * x * x;
        if (pows - prev > X) {
            break;
        }
        origs.push_back(x);
        elems.push_back(pows);
        prev = pows;
    }

    // for (int i = 0; i < (int) elems.size(); i++) {
    //     cout << elems[i] << endl;
    // }

    for (int i = 0; i < (int) elems.size(); i++) {
        for (int j = 0; j < (int) elems.size(); j++) {
            ll a = elems[i];
            ll b = elems[j];
            if (a + b == X) {
                printf("%lld %lld\n", origs[i], -1 * origs[j]);
                return 0;
            } else if (a - b == X) {
                printf("%lld %lld\n", origs[i], origs[j]);
                return 0;
            }
        }
    }

    return 0;
}
