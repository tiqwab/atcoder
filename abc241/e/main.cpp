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

// assume that K <= 1000 * 1000
ll calc_simply(const ll N, const ll K, const vector<ll> &as) {
    ll ans = 0;
    for (int i = 0; i < K; i++) {
        ll x = ans % N;
        ans += as[x];
    }
    return ans;
}

// {pre_loop_num, pre_loop_sum, loop_num, loop_sum, loop}
tuple<int, ll, int, ll, vector<ll>> find_loop(const ll N, const vector<ll> &as) {
    ll sum = 0;
    vector<ll> vs;
    vector<bool> visited(N, false);
    ll loop_start_v;

    while (true) {
        ll x = sum % N;
        if (visited[x]) {
            loop_start_v = x;
            break;
        }
        vs.push_back(x);
        visited[x] = true;
        sum += as[x];
    }

    sum = 0;
    int pre_loop_num = 0;
    ll pre_loop_sum = 0;
    int loop_num = 0;
    ll loop_sum = 0;
    vector<ll> loop;
    int start_i = 0;
    while (vs[start_i] != loop_start_v) {
        ll x = sum % N;
        sum += as[x];
        pre_loop_num++;
        start_i++;
    }
    pre_loop_sum = sum;
    for (int i = start_i; i < (int) vs.size(); i++) {
        loop_sum += as[vs[i]];
        loop_num++;
        loop.push_back(vs[i]);
    }

    return make_tuple(pre_loop_num, pre_loop_sum, loop_num, loop_sum, loop);
}

int main(void) {
    ll N, K;
    cin >> N >> K;

    vector<ll> as(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    if (K <= 1000 * 1000) {
        // just calculation
        printf("%lld\n", calc_simply(N, K, as));
        return 0;
    }

    auto find_loop_result = find_loop(N, as);
    int pre_loop_num;
    ll pre_loop_sum;
    int loop_num;
    ll loop_sum;
    vector<ll> loop;
    tie(pre_loop_num, pre_loop_sum, loop_num, loop_sum, loop) = find_loop_result;

#ifdef DEBUG
    printf("pre_loop_num: %d\n", pre_loop_num);
    printf("pre_loop_sum: %lld\n", pre_loop_sum);
    printf("loop_num: %d\n", loop_num);
    printf("loop_sum: %lld\n", loop_sum);
    printf("loop: ");
    for (auto x : loop) {
        printf("%lld ", x);
    }
    printf("\n");
#endif

    ll ans = 0;
    ll k = K;

    // pre_loop
    ans += pre_loop_sum;
    k -= pre_loop_num;

    // loop
    ans += (k / loop_num) * loop_sum;
    k %= loop_num;

    for (int i = 0; i < k; i++) {
        ll x = ans % N;
        ans += as[x];
    }

    cout << ans << endl;

    return 0;
}
