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

vector<int> as;

ll calc(const int mod, const int N, const ll X) {
    vector<map<int, ll>> dp(mod);
    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        const int a = as[i];
        vector<map<int, ll>> tmp = dp;
        for (int j = 0; j < mod; j++) {
            for (auto p : dp[j]) {
                const int num = p.first;
                const ll acc = p.second;
                if (num >= mod) {
                    continue;
                }
                auto it = tmp[(j + a) % mod].find(num + 1);
                if (it != tmp[(j + a) % mod].end()) {
                    if ((*it).second < acc + a) {
                        tmp[(j + a) % mod][num + 1] = acc + a;
                    }
                } else {
                    tmp[(j + a) % mod][num + 1] = acc + a;
                }
            }
        }
        dp = move(tmp);
    }

    return dp[X % mod][mod];
}

int main(void) {
    int N;
    ll X;
    cin >> N >> X;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    ll ans = INF;

    for (int i = 1; i <= N; i++) {
        // printf("mod=%d\n", i);
        ll acc = calc(i, N, X);
        if (acc != 0) {
            assert((X - acc) % i == 0);
            chmin(ans, (X - acc) / i);
        }
    }

    printf("%lld\n", ans);

    return 0;
}
