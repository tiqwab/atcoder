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

// dp1[i][j] means the destination of 2^i steps from j
vector<vector<int>> dp_to;
// dp2[i][j] means the sum of 2^i steps from j
vector<vector<ll>> dp_sum;

int main(void) {
    ll N, K;
    cin >> N >> K;

    vector<ll> as(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    dp_to.resize(40, vector<int>(N + 1, 0));
    for (int i = 0; i < N; i++) {
        dp_to[0][i] = (i + as[i]) % N;
    }

    dp_sum.resize(40, vector<ll>(N + 1, 0));
    for (int i = 0; i < N; i++) {
        dp_sum[0][i] = as[i];
    }

    for (int i = 0; i < 39; i++) {
        for (int j = 0; j < N; j++) {
            dp_to[i + 1][j] = dp_to[i][dp_to[i][j]];
            dp_sum[i + 1][j] = dp_sum[i][dp_to[i][j]] + dp_sum[i][j];
        }
    }
#ifdef DEBUG
    // printf("dp_to: \n");
    // for (int i = 0; i < 40; i++) {
    //     for (int j = 0; j < N; j++) {
    //         printf("%d ", dp_to[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("dp_sum: \n");
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < N; j++) {
            printf("%lld ", dp_sum[i][j]);
        }
        printf("\n");
    }
#endif

    ll ans = 0;
    int pos = 0;
    for (int i = 0; i < 40; i++) {
        if (K & (1LL << i)) {
            ans += dp_sum[i][pos];
            pos = dp_to[i][pos];
        }
    }
    cout << ans << endl;

    return 0;
}
