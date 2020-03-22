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

vector<vector<int>> board; // 0 is white, 1 is black
vector<vector<ll>> dp;

ll solve(const int cur_h, const int cur_w, const int H, const int W) {
    if (dp[cur_h][cur_w] != -1) {
        return dp[cur_h][cur_w];
    }

    int cur_color = board[cur_h][cur_w];
    if (cur_color == 0) {
        // white
        dp[cur_h][cur_w] = min(solve(cur_h + 1, cur_w, H, W), solve(cur_h, cur_w + 1, H, W));
    } else {
        // black
        ll cand_up = INF, cand_left = INF;
        {
            // up
            if (cur_h + 1 <= H) {
                cand_up = solve(cur_h + 1, cur_w, H, W);
                if (board[cur_h + 1][cur_w] == 0) {
                    cand_up++;
                }
            }
        }
        {
            // left
            if (cur_w + 1 <= W) {
                cand_left = solve(cur_h, cur_w + 1, H, W);
                if (board[cur_h][cur_w + 1] == 0) {
                    cand_left++;
                }
            }
        }
        dp[cur_h][cur_w] = min(cand_up, cand_left);
    }

    return dp[cur_h][cur_w];
}

int main(void) {
    int H, W;
    cin >> H >> W;

    board.resize(H + 3, vector<int>(W + 3, 1));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c;
            cin >> c;
            if (c == '.') {
                board[i + 1][j + 1] = 0;
            } else {
                board[i + 1][j + 1] = 1;
            }
        }
    }


    dp.resize(H + 3, vector<ll>(W + 3, -1));
    for (int i = 0; i < H; i++) {
        dp[i][0] = INF;
        dp[i][W + 1] = INF;
    }
    for (int i = 0; i < W; i++) {
        dp[0][i] = INF;
        dp[H + 1][i] = INF;
    }
    dp[H][W] = (board[H][W] == 0) ? 0 : 1;

    cout << solve(1, 1, H, W) << endl;

    return 0;
}
