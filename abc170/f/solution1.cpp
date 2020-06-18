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

// {h, w}
const vector<pair<int, int>> diff_for_dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

vector<vector<char>> board;

// dp[i][j][k] means the smallest cost from (x1, y1) to (i, j) with direction k.
// {cost, steps used}
vector<vector<vector<pair<int, int>>>> dp;

void solve(const int start_h, const int start_w, const int H, const int W, const int K) {
    // {cost, steps used, h, w, dir}
    typedef tuple<int, int, int, int, int> Elem;
    priority_queue<Elem, vector<Elem>, greater<Elem>> que;
    que.push({0, 0, start_h, start_w, 0});
    que.push({0, 0, start_h, start_w, 1});
    que.push({0, 0, start_h, start_w, 2});
    que.push({0, 0, start_h, start_w, 3});

    while (!que.empty()) {
        int cur_cost, cur_steps, cur_h, cur_w, cur_dir;
        tie(cur_cost, cur_steps, cur_h, cur_w, cur_dir) = que.top();
        que.pop();
        const pair<int, int> cur_state = {cur_cost, cur_steps};

        if (dp[cur_h][cur_w][cur_dir] < cur_state) {
            continue;
        }

        // change direction
        for (int ndir = 0; ndir < 4; ndir++) {
            pair<int, int> next_state = {cur_state.first + 1, 0};
            if (dp[cur_h][cur_w][ndir] > next_state) {
                dp[cur_h][cur_w][ndir] = next_state;
                que.push({next_state.first, next_state.second, cur_h, cur_w, ndir});
            }
        }

        // proceed on the same direction
        int next_h = cur_h + diff_for_dir[cur_dir].first;
        int next_w = cur_w + diff_for_dir[cur_dir].second;
        if (next_h > 0 && next_h <= H && next_w > 0 && next_w <= W 
                && board[next_h][next_w] != '@') {
            pair<int, int> next_state;
            if (cur_steps < K) {
                next_state = {cur_cost, cur_steps + 1};
            } else {
                next_state = {cur_cost + 1, 1};
            }

            if (dp[next_h][next_w][cur_dir] > next_state) {
                dp[next_h][next_w][cur_dir] = next_state;
                que.push({next_state.first, next_state.second, next_h, next_w, cur_dir});
            }
        }
    }
}

int main(void) {
    int H, W, K;
    cin >> H >> W >> K;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    board.resize(H + 2, vector<char>(W + 2, '@'));
    for (int h = 1; h <= H; h++) {
        for (int w = 1; w <= W; w++) {
            char c;
            cin >> c;
            if (c == '.') {
                board[h][w] = '.';
            }
        }
    }

    dp.resize(H + 2);
    for (int h = 0; h < H + 2; h++) {
        dp[h].resize(W + 2);
        for (int w = 0; w < W + 2; w++) {
            dp[h][w].resize(4);
            for (int dir = 0; dir < 4; dir++) {
                dp[h][w][dir] = {INF, INF};
                dp[h][w][dir] = {INF, INF};
                dp[h][w][dir] = {INF, INF};
                dp[h][w][dir] = {INF, INF};
            }
        }
    }
    dp[x1][y1][0] = {0, 0};
    dp[x1][y1][1] = {0, 0};
    dp[x1][y1][2] = {0, 0};
    dp[x1][y1][3] = {0, 0};

    solve(x1, y1, H, W, K);

    int ans = INF;
    for (int dir = 0; dir < 4; dir++) {
        chmin(ans, dp[x2][y2][dir].first + 1);
    }
    if (ans == INF) {
        ans = -1;
    }
    cout << ans << endl;

    // for (int dir = 0; dir < 4; dir++) {
    //     printf("dir: %d\n", dir);
    //     for (int h = 0; h <= H + 1; h++) {
    //         for (int w = 0; w <= W + 1; w++) {
    //             printf("%10d ", dp[h][w][dir].first);
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }

    return 0;
}
