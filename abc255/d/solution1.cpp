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
    int N, Q;
    cin >> N >> Q;

    vector<ll> as;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        as.push_back(a);
    }
    sort(as.begin(), as.end());

    vector<pair<ll, int>> qs;
    for (int i = 0; i < Q; i++) {
        ll q;
        cin >> q;
        qs.push_back(make_pair(q, i));
    }
    sort(qs.begin(), qs.end());

    ll acc = 0;
    for (int i = 0; i < N; i++) {
        acc += as[i];
    }

    ll prev_q = 0;
    ll n_passed = 0;
    vector<ll> ans(Q);
    for (auto q : qs) {
        for (; n_passed < N && as[n_passed] < q.first; n_passed++) {
            acc -= (as[n_passed] - prev_q) * 2;
        }
        acc -= (q.first - prev_q) * (N - n_passed);
        acc += (q.first - prev_q) * n_passed;
        ans[q.second] = acc;
        prev_q = q.first;
    }

    for (int i = 0; i < Q; i++) {
        printf("%lld\n", ans[i]);
    }

    return 0;
}
