#include <algorithm>
#include <cassert>
#include <iostream>
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

vector<ll> A;
vector<ll> ms;
vector<ll> ps;

/*
 * Check if there are more than K pairs exceeding v.
 */
bool check_minus(const ll v, const ll K) {
    const int mslen = (int) ms.size();

    ll acc = 0;
    for (int i = 0; i < mslen; i++) {
        auto it = upper_bound(ps.begin(), ps.end(), v / ms[i]);
        // printf("m: %d, %ld\n", ms[i], it - ps.begin());
        acc += ps.end() - it;
    }
    // printf("v: %lld, K: %d, acc: %lld\n", v, K, acc);
    return acc < K;
}

ll solve_minus(const ll N, const ll K) {
    ll left = -INF, mid, right = 0;
    while (right - left > 1) {
        // printf("left: %lld, right: %lld\n", left, right);
        mid = (right - left) / 2 + left;
        if (check_minus(mid, K)) left = mid;
        else right = mid;
    }

    return left;
}

bool check_plus(const ll v, const ll K) {
    const int mslen = (int) ms.size();
    const int pslen = (int) ps.size();

    ll acc = 0;
    for (int i = 0; i < pslen; i++) {
        ll div = (v - 1) / ps[i];
        auto it = upper_bound(ps.begin(), ps.end(), div);
        int diff = it - (ps.begin() + i);
        diff--;
        if (diff <= 0) continue;
        // printf("p: %d, %ld\n", ps[i], it - (ps.begin() + i));
        acc += diff;
    }

    // convert each item of ms to absolute value, then reverse
    int nslen = mslen;
    vector<ll> ns(nslen);
    for (int i = 0; i < nslen; i++) {
        ns[i] = -1 * ms[i];
    }
    reverse(ns.begin(), ns.end());

    for (int i = 0; i < nslen; i++) {
        ll div = (v - 1) / ns[i];
        auto it = upper_bound(ns.begin(), ns.end(), div);
        int diff = it - (ns.begin() + i);
        diff--;
        if (diff <= 0) continue;
        // printf("m: %d, %ld\n", ns[i], it - (ns.begin() + i));
        acc += diff;
    }

    // printf("v: %lld, K: %d, acc: %lld\n", v, K, acc);
    return acc < K;
}

ll solve_plus(const ll N, const ll K) {
    ll left = 1, mid, right = INF;
    while (right - left > 1) {
        // printf("left: %lld, right: %lld\n", left, right);
        mid = (right - left) / 2 + left;
        if (check_plus(mid, K)) left = mid;
        else right = mid;
    }

    return left;
}

int main(void) {
    ll N, K;
    cin >> N >> K;
    ll num_minus = 0;
    ll num_zero = 0;
    ll num_plus = 0;

    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] > 0) {
            num_plus++;
            ps.push_back(A[i]);
        } else if (A[i] == 0) {
            num_zero++;
        } else {
            num_minus++;
            ms.push_back(A[i]);
        }
    }

    sort(ms.begin(), ms.end());
    sort(ps.begin(), ps.end());

    const ll num_minus_pairs = num_minus * num_plus;
    const ll num_zero_pairs = (N * (N - 1) / 2) - ((N - num_zero) * (N - num_zero - 1) / 2);
    const ll num_plus_pairs = (N * (N - 1) / 2) - num_minus_pairs - num_zero_pairs;
    // printf("%lld, %lld, %lld\n", num_minus_pairs, num_zero_pairs, num_plus_pairs);

    ll ans;
    if (K <= num_minus_pairs) {
        ans = solve_minus(N, K);
    } else if (K <= num_minus_pairs + num_zero_pairs) {
        ans = 0LL;
    } else {
        ans = solve_plus(N, K - num_minus_pairs - num_zero_pairs);
    }

    cout << ans << endl;

    return 0;
}
