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

vector<vector<ll>> items;

vector<vector<vector<ll>>> dp;

void solve(const int R, const int C, const int K) {
    for (int r = 0; r <= R; r++) {
        for (int c = 0; c <= C; c++) {
            for (int n = 0; n < 4; n++) {
#ifdef DEBUG
                printf("r: %d, c: %d, n: %d, score: %lld\n", r, c, n, dp[r][c][n]);
#endif
                // down
                if (r < R) {
                    // get item
#ifdef DEBUG
                    printf("[down, get] += %lld\n", items[r + 1][c]);
#endif
                    chmax(dp[r + 1][c][1], dp[r][c][n] + items[r + 1][c]);

                    // not get item
                    chmax(dp[r + 1][c][0], dp[r][c][n]);
                }

                // right
                if (c < C) {
                    // get item
                    if (n < 3) {
#ifdef DEBUG
                        printf("[right, get] += %lld\n", items[r][c + 1]);
#endif
                        chmax(dp[r][c + 1][n + 1], dp[r][c][n] + items[r][c + 1]);
                    }

                    // not get item
                    chmax(dp[r][c + 1][n], dp[r][c][n]);
                }
            }
        }
    }
}

int main(void) {
    int R, C, K;
    cin >> R >> C >> K;

    items.resize(R + 1, vector<ll>(C + 1, 0LL));
    for (int k = 0; k < K; k++) {
        int r, c, v;
        cin >> r >> c >> v;
        items[r][c] = v;
    }

    dp.resize(R + 1);
    for (int r = 0; r <= R; r++) {
        dp[r].resize(C + 1, vector<ll>(4, 0));
    }

    solve(R, C, K);

    ll ans = 0;
    for (int i = 0; i < 4; i++) {
        chmax(ans, dp[R][C][i]);
    }
    cout << ans << endl;

    return 0;
}
