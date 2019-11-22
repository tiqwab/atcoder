#include <algorithm>
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

const int MAX_N = 300;
const int MAX_K = 300;

ll dp[MAX_N + 2][MAX_N + 2];

void print_dp(int n, int k, ll table[MAX_N + 2][MAX_N + 2]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}

/*
 * ref. https://atcoder.jp/contests/abc145/submissions/8473073
 */
int main(void) {
    int N, K;
    cin >> N >> K;

    vector<int> h(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> h[i];
    }

    for (int i = 0; i < MAX_N + 2; i++) {
        for (int j = 0; j < MAX_N + 2; j++) {
            // Avoid to use LONG_LONG_MAX
            // because it causes overflow.
            dp[i][j] = LONG_LONG_MAX / 2;
        }
    }

    // dp[x][y]: size is x, the most right one is y.
    dp[0][0] = 0;
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            for (int z = 0; z < y; z++) {
                chmin(dp[x][y], dp[x - 1][z] + max(0, h[y] - h[z]));
            }
        }
    }

    // print_dp(N + 1, N + 1, dp);

    ll min = LONG_LONG_MAX;
    // x should start zero for edge case
    // where N == K (returning always zero.)
    for (int x = 0; x <= N; x++) {
        chmin(min, dp[N - K][x]);
    }

    cout << min << endl;
    
    return 0;
}
