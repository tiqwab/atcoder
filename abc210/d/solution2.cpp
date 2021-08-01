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

vector<vector<ll>> board;

// ref. https://atcoder.jp/contests/abc210/editorial/2298
int main(void) {
    int H, W;
    ll C;
    cin >> H >> W >> C;

    board.resize(H, vector<ll>(W, 0));
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            cin >> board[h][w];
        }
    }

    auto solve = [](const vector<vector<ll>> &board, const int H, const int W, const int C) {
        vector<vector<ll>> dp(H, vector<ll>(W, INF));

        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                ll cand = board[h][w];
                if (h > 0) {
                    chmin(cand, dp[h - 1][w] + C);
                }
                if (w > 0) {
                    chmin(cand, dp[h][w - 1] + C);
                }
                dp[h][w] = cand;
            }
        }

        ll ans = INF;

        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                ll cand = INF;
                if (h > 0) {
                    chmin(cand, dp[h - 1][w] + C + board[h][w]);
                }
                if (w > 0) {
                    chmin(cand, dp[h][w - 1] + C + board[h][w]);
                }
                chmin(ans, cand);
            }
        }

        return ans;
    };

    ll ans = solve(board, H, W, C);
    reverse(board.begin(), board.end());
    chmin(ans, solve(board, H, W, C));
    cout << ans << endl;

    return 0;
}
