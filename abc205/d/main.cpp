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

// {a, empty numbers less than me}
map<ll, ll> pos;

ll solve(const ll K) {
    int left = 0;
    int right = ((int) pos.size()) - 1;

    while (right - left > 1) {
        int mid = left + (right - left) / 2;
#ifdef DEBUG
        printf("left: %d, right: %d, mid: %d\n", left, right, mid);
#endif
        ll a = as[mid];
        ll nums_less_than_a = pos[a]; 
#ifdef DEBUG
        printf("a: %lld, nums_less_than_a: %lld\n", a, nums_less_than_a);
#endif
        if (nums_less_than_a >= K) {
            right = mid;
        } else {
            left = mid;
        }
    }

    ll a = as[left];
    ll nums_less_than = pos[a];
    return a + (K - nums_less_than);
}

int main(void) {
    int N, Q;
    cin >> N >> Q;

    as.push_back(0);
    pos[0] = 0;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        as.push_back(a);
        pos[a] = a - (i + 1);
    }
    as.push_back(LONG_LONG_MAX / 2);
    pos[LONG_LONG_MAX / 2] = LONG_LONG_MAX / 2 - N;

    for (int i = 0; i < Q; i++) {
        ll K;
        cin >> K;
        printf("%lld\n", solve(K));
    }
    return 0;
}
