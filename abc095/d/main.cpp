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

const ll INF = LONG_LONG_MAX / 2;

// {posision, value}
vector<pair<ll, ll>> r_sushis;
vector<pair<ll, ll>> l_sushis;

// acc of value
vector<ll> r_acc;
vector<ll> l_acc;

// arr[i] is the best position if Nakahashi goes to position i and go back to the start.
vector<ll> r_best;
vector<ll> l_best;

int main(void) {
    int N;
    ll C;
    cin >> N >> C;

    r_sushis.resize(N + 1);
    r_sushis[0] = {0, 0};
    l_sushis.resize(N + 1);
    l_sushis[0] = {0, 0};
    for (int i = 1; i <= N; i++) {
        ll x, v;
        cin >> x >> v;
        r_sushis[i] = {x, v};
        l_sushis[N - i + 1] = {C - x, v};
    }

#ifdef DEBUG
    printf("r_sushis: ");
    for (auto p : r_sushis) {
        printf("{%lld, %lld}, ", p.first, p.second);
    }
    printf("\n");

    printf("l_sushis: ");
    for (auto p : l_sushis) {
        printf("{%lld, %lld}, ", p.first, p.second);
    }
    printf("\n");
#endif

    r_acc.resize(N + 1, 0);
    l_acc.resize(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        r_acc[i] = r_acc[i - 1] + r_sushis[i].second;
        l_acc[i] = l_acc[i - 1] + l_sushis[i].second;
    }

#ifdef DEBUG
    printf("r_acc: ");
    for (auto x : r_acc) {
        printf("%lld, ", x);
    }
    printf("\n");

    printf("l_acc: ");
    for (auto x : l_acc) {
        printf("%lld, ", x);
    }
    printf("\n");
#endif

    {
        r_best.resize(N + 1, 0);
        l_best.resize(N + 1, 0);
        ll acc = 0;
        for (int i = 1; i <= N; i++) {
            acc += r_sushis[i].second;
            r_best[i] = max(r_best[i - 1], acc - 2 * r_sushis[i].first);
        }

        acc = 0;
        for (int i = 1; i <= N; i++) {
            acc += l_sushis[i].second;
            l_best[i] = max(l_best[i - 1], acc - 2 * l_sushis[i].first);
        }

#ifdef DEBUG
        printf("r_best: ");
        for (auto x : r_best) {
            printf("%lld ", x);
        }
        printf("\n");

        printf("l_best: ");
        for (auto x : l_best) {
            printf("%lld ", x);
        }
        printf("\n");
#endif
    }

    ll ans = 0;

    // when go right first, then go left
    for (int nl = 1; nl <= N; nl++) {
        int nr = N - nl;
        ll cand = 0;
        cand += r_best[nr];
        cand += l_acc[nl];
        cand -= l_sushis[nl].first;
#ifdef DEBUG
        printf("nl: %d, cand: %lld\n", nl, cand);
#endif
        chmax(ans, cand);
    }

    // when go left first, then go right
    for (int nr = 1; nr <= N; nr++) {
        int nl = N - nr;
        ll cand = 0;
        cand += l_best[nl];
        cand += r_acc[nr];
        cand -= r_sushis[nr].first;
#ifdef DEBUG
        printf("nr: %d, cand: %lld\n", nr, cand);
#endif
        chmax(ans, cand);
    }

    cout << ans << endl;

    return 0;
}
