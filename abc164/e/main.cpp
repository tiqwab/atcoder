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

const int MAX_M = 100;
const int MAX_A = 50;
const int MAX_SILVERS = MAX_M * MAX_A + 10;
const ll INF = LONG_LONG_MAX / 2;

// {to, money, time}
vector<vector<tuple<int, int, int>>> edges;

// dp[pos][money] = minimum time
vector<vector<ll>> dp;

void solve(const int N, const int M, const int S) {
    // {time, pos, money}
    priority_queue<
        tuple<ll, int, int>,
        vector<tuple<ll, int, int>>,
        greater<tuple<ll, int, int>>> que;

    que.push({0, 0, S});

    while (!que.empty()) {
        ll cur_time;
        int cur_pos, cur_money;
        tie(cur_time, cur_pos, cur_money) = que.top();
        que.pop();
        // printf("cur_time: %lld, cur_pos: %d, cur_money: %d\n", cur_time, cur_pos, cur_money);

        for (auto &edge : edges[cur_pos]) {
            ll to_time;
            int to_pos, to_money;
            tie(to_pos, to_money, to_time) = edge;
            ll cand_time = dp[cur_pos][cur_money] + to_time;
            ll cand_money = cur_money + to_money;
            if (cand_money < 0 || cand_money > MAX_SILVERS) {
                continue;
            }
            if (cand_time < dp[to_pos][cand_money]) {
                dp[to_pos][cand_money] = cand_time;
                que.push({cand_time, to_pos, cand_money});
            }
        }
    }
}

int main(void) {
    int N, M, S;
    cin >> N >> M >> S;

    if (S > MAX_SILVERS) {
        S = MAX_SILVERS;
    }

    edges.resize(N);

    for (int i = 0; i < M; i++) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        u--;
        v--;
        edges[u].push_back({v, -a, b});
        edges[v].push_back({u, -a, b});
    }

    for (int i = 0; i < N; i++) {
        int c, d;
        cin >> c >> d;
        edges[i].push_back({i, c, d});
    }

    dp.resize(N, vector<ll>(MAX_SILVERS + 1, INF));
    dp[0][S] = 0;

    solve(N, M, S);

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < 50; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    for (int i = 1; i < N; i++) {
        ll ans = INF;
        for (int j = 0; j <= MAX_SILVERS; j++) {
            chmin(ans, dp[i][j]);
        }
        cout << ans << endl;
    }

    return 0;
}
