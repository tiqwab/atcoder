#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>

// using namespace std;

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

std::map<ll, ll> acc;
std::map<ll, ll> next;

const int N = 1 << 20;

ll dfs(const ll h, const ll x) {
    if (acc.find(h) == acc.end()) {
        acc[h] = x;
        next[h] = (h + 1) % N;
#ifdef DEBUG
        printf("next[%lld] set to %lld\n", h, (h + 1) % N);
#endif
        return next[h];
    } else {
        const ll nh = dfs(next[h], x);
        next[h] = nh;
#ifdef DEBUG
        printf("next[%lld] set to %lld\n", h, nh);
#endif
        return nh;
    }
}

int main(void) {
    int Q;
    std::cin >> Q;

    for (int i = 0; i < Q; i++) {
        int t;
        ll x;
        std::cin >> t >> x;

        if (t == 1) {
            ll h = x % N;
            dfs(h, x);
        } else {
            ll h = x % N;
            if (acc.find(h) != acc.end()) {
                printf("%lld\n", acc[h]);
            } else {
                printf("%d\n", -1);
            }
        }
    }

#ifdef DEBUG
    for (auto p : acc) {
        printf("%lld: %lld\n", p.first, p.second);
    }
#endif

    return 0;
}
