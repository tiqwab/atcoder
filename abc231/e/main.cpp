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

ll f(const ll target, const int cur_index, const vector<ll> &as, const int N) {
    static map<pair<ll, int>, ll> memo;

    if (memo.find(make_pair(target, cur_index)) != memo.end()) {
        return memo[make_pair(target, cur_index)];
    }

    ll ans = INF;

    const ll a = as[cur_index];
    const ll q = target / a;

    if (target % a == 0) {
        return q;
    }

    if (cur_index < N - 1) {
        chmin(ans, q + f(target % a, cur_index + 1, as, N));
        chmin(ans, q + 1 + f(a - (target % a), cur_index + 1, as, N));
    }

    memo[make_pair(target, cur_index)] = ans;
    return ans;
}

// Another good input is:
// 5 34
// 1 8 40 280 560
// -> answer is 4 (pay by 40 * 1 + 1 * 2, charge is 8 * 1)
int main(void) {
    int N;
    ll X;
    cin >> N >> X;

    vector<ll> as(N);
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        as[i] = a;
    }
    reverse(as.begin(), as.end());

    printf("%lld\n", f(X, 0, as, N));

    return 0;
}
