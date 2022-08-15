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

multiset<ll> se;

int main(void) {
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int inst;
        cin >> inst;
        if (inst == 1) {
            ll x;
            cin >> x;
            se.insert(x);
        } else if (inst == 2) {
            ll x;
            int k;
            cin >> x >> k;
            auto it = se.upper_bound(x);
            bool ok = true;
            for (int i = 0; i < k; i++) {
                if (it == se.begin()) {
                    ok = false;
                    break;
                }
                it--;
            }
            if (ok) {
                printf("%lld\n", *it);
            } else {
                printf("-1\n");
            }
        } else {
            ll x;
            int k;
            cin >> x >> k;
            auto it = se.lower_bound(x);
            if (it == se.end()) {
                printf("-1\n");
                continue;
            }
            bool ok = true;
            for (int i = 1; i < k; i++) {
                it++;
                if (it == se.end()) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                printf("%lld\n", *it);
            } else {
                printf("-1\n");
            }
        }
    }

    return 0;
}
