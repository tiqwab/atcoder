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

vector<vector<int>> dp;

void solve(const int start_h, const int start_w, const int H, const int W, const int K) {
    queue<pair<int, int>> que;

    dp[start_h][start_w] = 0;
    que.push({start_h, start_w});

    while (!que.empty()) {
        const int cur_h = que.front().first;
        const int cur_w = que.front().second;
        const int cur_dist = dp[cur_h][cur_w];
        que.pop();

        for (int dir = 0; dir < 4; dir++) {
            int next_h = cur_h;
            int next_w = cur_w;
            int dist = cur_dist + 1;
            for (int step = 1; step <= K; step++) {
                next_h += diff_for_dir[dir].first;
                next_w += diff_for_dir[dir].second;
                if (next_h < 1 || next_h > H || next_w < 1 || next_w > W
                        || board[next_h][next_w] != '.' || dp[next_h][next_w] < dist) {
                    break;
                }

                // dp[next_h][next_w] < dist is true if it reaches here, but it sometimes have to avoid recalculation.
                // e.g. we are at the posion specified by '*' (assume that the position is (i, j)) and going up,
                // we don't have to recalculate (i - 1, j), but we have to go to (i - 2, j) and update it to 3 if K >= 2.
                // INF INF INF
                // 3   3   3 
                // 2   3*  INF
                if (dist < dp[next_h][next_w]) {
                    dp[next_h][next_w] = dist;
                    que.push({next_h, next_w});
                }
            }
        }
    }
}

// solution explaind as the 2nd soltuion in the video
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

    dp.resize(H + 2, vector<int>(W + 2, INF));

    solve(x1, y1, H, W, K);

    int ans = dp[x2][y2];
    if (ans == INF) {
        ans = -1;
    }
    cout << ans << endl;

    return 0;
}
