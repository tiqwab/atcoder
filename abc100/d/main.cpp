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

vector<tuple<ll, ll, ll>> cakes;

ll calc_based_on(bool sign_x, bool sign_y, bool sign_z, const int N, const int M) {
    vector<ll> values(N);

    for (int i = 0; i < N; i++) {
        ll x, y, z;
        tie(x, y, z) = cakes[i];

        // printf("x: %lld, y: %lld, z: %lld\n", x, y, z);

        vector<ll> xyz = {x, y, z};
        vector<bool> sign_xyz = {sign_x, sign_y, sign_z};
        ll v = 0;

        for (int j = 0; j < 3; j++) {
            if (sign_xyz[j]) {
                v += xyz[j];
            } else {
                v -= xyz[j];
            }
        }

        // printf("v: %lld\n", v);
        values[i] = v;
    }

    sort(values.begin(), values.end());
    reverse(values.begin(), values.end());

    ll acc = 0;
    for (int i = 0; i < M; i++) {
        // printf("v: %lld\n", values[i]);
        acc += values[i];
    }

    // printf("sign_x: %d, sign_y: %d, sign_z: %d, acc: %lld\n", sign_x, sign_y, sign_z, acc);
    return acc;
}

ll solve(const int N, const int M) {
    ll ans = 0;
    chmax(ans, calc_based_on(true, true, true, N, M));
    chmax(ans, calc_based_on(true, true, false, N, M));
    chmax(ans, calc_based_on(true, false, true, N, M));
    chmax(ans, calc_based_on(true, false, false, N, M));
    chmax(ans, calc_based_on(false, true, true, N, M));
    chmax(ans, calc_based_on(false, true, false, N, M));
    chmax(ans, calc_based_on(false, false, true, N, M));
    chmax(ans, calc_based_on(false, false, false, N, M));
    return ans;
}

int main(void) {
    int N, M;
    cin >> N >> M;

    cakes.resize(N);
    for (int i = 0; i < N; i++) {
        ll x, y, z;
        cin >> x >> y >> z;
        cakes[i] = tie(x, y, z);
    }

    cout << solve(N, M) << endl;

    return 0;
}
