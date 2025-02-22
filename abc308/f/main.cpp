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
    int N, M;
    cin >> N >> M;

    ll sum_price = 0;

    multiset<ll> ps;
    for (int i = 0; i < N; i++) {
        ll p;
        cin >> p;
        ps.insert(p);
        sum_price += p;
    }

    vector<ll> ls;
    for (int i = 0; i < M; i++) {
        ll l;
        cin >> l;
        ls.push_back(l);
    }

    vector<ll> ds;
    for (int i = 0; i < M; i++) {
        ll d;
        cin >> d;
        ds.push_back(d);
    }

    // {l, d}
    // l: 定価 l 円以上の商品に使える
    // d: d 円割引
    vector<pair<ll, ll>> vouchers; 
    for (int i = 0; i < M; i++) {
        vouchers.push_back(make_pair(ls[i], ds[i]));
    }
    sort(vouchers.begin(), vouchers.end(), [](const pair<ll, ll>& lhs, const pair<ll, ll>& rhs) {
        if (lhs.second != rhs.second) {
            return lhs.second < rhs.second;
        }
        return lhs.first < rhs.first;
    });
    reverse(vouchers.begin(), vouchers.end());

    ll discount_sum = 0;
    for (int i = 0; i < M; i++) {
        pair<ll, ll> voucher = vouchers[i];
        ll l = voucher.first;
        ll d = voucher.second;

        auto it = ps.lower_bound(l);
        if (it == ps.end()) {
            continue;
        }
#ifdef DEBUG
        printf("use (l=%lld, d=%lld) for %lld\n", l, d, distance(ps.begin(), it));
#endif
        discount_sum += d;
        ps.erase(it);
    }

    printf("%lld\n", sum_price - discount_sum);

    return 0;
}
