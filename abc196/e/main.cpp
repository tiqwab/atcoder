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

const ll INF = INT_MAX / 2;

// {a, t}
vector<pair<ll, int>> fs;

ll calc(ll x, const int N) {
    ll ans = x;
    for (int i = 0; i < N; i++) {
        const ll a = fs[i].first;
        const int t = fs[i].second;
        if (t == 1) {
            ans += a;
        } else if (t == 2) {
            ans = max(ans, a);
        } else {
            ans = min(ans, a);
        }
    }
    return ans;
}

int main(void) {
    int N;
    cin >> N;

    fs.resize(N);
    for (int i = 0; i < N; i++) {
        int a, t;
        cin >> a >> t;
        fs[i] = make_pair(a, t);
    }

    int Q;
    cin >> Q;

    const ll v_min = calc(-INF, N);
    const ll v_max = calc(INF, N);
#ifdef DEBUG
    printf("v_min: %lld, v_max: %lld\n", v_min, v_max);
#endif

    ll acc = 0;
    for (int i = 0; i < N; i++) {
        const ll a = fs[i].first;
        const int t = fs[i].second;
        if (t == 1) {
            acc += a;
        }
    }

    for (int i = 0; i < Q; i++) {
        ll x;
        cin >> x;
        if (x < v_min - acc) {
            printf("%lld\n", v_min);
        } else if (v_max - acc < x) {
            printf("%lld\n", v_max);
        } else {
            printf("%lld\n", x + acc);
        }
    }

    return 0;
}
