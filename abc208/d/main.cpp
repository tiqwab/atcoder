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

// {to, cost}
vector<vector<pair<int, int>>> edges;

ll accumulate(vector<vector<int>> &dp, const int N) {
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dp[i][j] != INF) {
                ans += dp[i][j];
            }
        }
    }
    return ans;
}

int main(void) {
    int N, M;
    cin >> N >> M;

    edges.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges[a].push_back(make_pair(b, c));
    }

    vector<vector<int>> dp(N, vector<int>(N, INF));

    for (int i = 0; i < N; i++) {
        dp[i][i] = 0;
    }
    for (int i = 0; i < N; i++) {
        for (auto edge : edges[i]) {
            dp[i][edge.first] = edge.second;
        }
    }

    ll ans = 0;

    for (int k = 0; k < N; k++) {
        vector<vector<int>> tmp = dp;
        for (int from = 0; from < N; from++) {
            for (int to = 0; to < N; to++) {
                int cand = dp[from][to];
                chmin(cand, dp[from][k] + dp[k][to]);
                tmp[from][to] = cand;
            }
        }
        swap(dp, tmp);
        ans += accumulate(dp, N);
    }

    cout << ans << endl;

    return 0;
}
