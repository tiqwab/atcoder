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

const int INF = INT_MAX / 2;

vector<int> as;
vector<int> bs;

vector<vector<int>> dp;

int dfs(const int n, const int m, const int N, const int M) {
    if (dp[n][m] != INF) {
        return dp[n][m];
    }

    int ans = INF;

    if (as[n] == bs[m]) {
        chmin(ans, dfs(n - 1, m - 1, N, M));
    }
    if (m > 0 && n > 0) {
        chmin(ans, dfs(n - 1, m - 1, N, M) + 1);
    }
    if (m > 0) {
        chmin(ans, dfs(n, m - 1, N, M) + 1);
    }
    if (n > 0) {
        chmin(ans, dfs(n - 1, m, N, M) + 1);
    }

    dp[n][m] = ans;

    return ans;
}

int main(void) {
    int N, M;
    cin >> N >> M;

    as.resize(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> as[i + 1];
    }

    bs.resize(M + 1);
    for (int i = 0; i < M; i++) {
        cin >> bs[i + 1];
    }

    dp.resize(N + 1, vector<int>(M + 1, INF));
    dp[0][0] = 0;
    dp[0][1] = 1;
    dp[1][0] = 1;

    int ans = dfs(N, M, N, M);
#ifdef DEBUG
    printf("dp: \n");
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
#endif
    cout << ans << endl;

    return 0;
}
