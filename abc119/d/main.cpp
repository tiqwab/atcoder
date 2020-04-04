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

const ll INF = LONG_LONG_MAX / 4;

vector<ll> ss;
vector<ll> ts;

ll solve(const ll x) {
    auto p_s = lower_bound(ss.begin(), ss.end(), x);
    p_s--;
    ll cand_s_1 = *p_s;
    ll cand_s_2 = *(p_s + 1);

    auto p_t = lower_bound(ts.begin(), ts.end(), x);
    p_t--;
    ll cand_t_1 = *p_t;
    ll cand_t_2 = *(p_t + 1);

    auto f = [](const ll x, const ll _s, const ll _t) {
        ll s, t;
        s = min(_s, _t);
        t = max(_s, _t);
        // printf("calc for x: %lld, s: %lld, t: %lld -> ", x, s, t);

        ll ans;
        if (x <= s) {
            ans = t - x;
        } else if (x >= t) {
            ans = x - s;
        } else {
            ans = abs(s - t) + min(abs(x - s), abs(x - t));
        }
        // printf("%lld\n", t - x);

        return ans;
    };

    ll ans = INF;
    chmin(ans, f(x, cand_s_1, cand_t_1));
    chmin(ans, f(x, cand_s_1, cand_t_2));
    chmin(ans, f(x, cand_s_2, cand_t_1));
    chmin(ans, f(x, cand_s_2, cand_t_2));
    return ans;
}

int main(void) {
    int A, B, Q;
    cin >> A >> B >> Q;

    ss.resize(A + 2);
    ss[0] = -INF;
    for (int i = 1; i <= A; i++) {
        cin >> ss[i];
    }
    ss[A + 1] = INF;

    ts.resize(B + 2);
    ts[0] = -INF;
    for (int i = 1; i <= B; i++) {
        cin >> ts[i];
    }
    ts[B + 1] = INF;

    for (int i = 0; i < Q; i++) {
        ll x;
        cin >> x;
        cout << solve(x) << endl;
    }

    return 0;
}
