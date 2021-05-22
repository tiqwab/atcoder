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

int main(void) {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> board(H, vector<char>(W));
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            cin >> board[h][w];
        }
    }

    vector<vector<int>> dp(H, vector<int>(W, 0));
    for (int h = H - 1; h >= 0; h--) {
        for (int w = W - 1; w >= 0; w--) {
            if (h == H - 1 && w == W - 1) {
                continue;
            }

            // turn == true if this is Takahashi's turn, otherwise Aoki's turn
            const bool turn = ((h + w) % 2) == 0;
            if (turn) {
                int cand = -INF;
                if (h < H - 1) {
                    // down
                    int profit = board[h + 1][w] == '+' ? 1 : -1;
                    chmax(cand, dp[h + 1][w] + profit);
                }
                if (w < W - 1) {
                    // right
                    int profit = board[h][w + 1] == '+' ? 1 : -1;
                    chmax(cand, dp[h][w + 1] + profit);
                }
                dp[h][w] = cand;
            } else {
                int cand = INF;
                if (h < H - 1) {
                    // down
                    int profit = board[h + 1][w] == '+' ? -1 : 1;
                    chmin(cand, dp[h + 1][w] + profit);
                }
                if (w < W - 1) {
                    // right
                    int profit = board[h][w + 1] == '+' ? -1 : 1;
                    chmin(cand, dp[h][w + 1] + profit);
                }
                dp[h][w] = cand;
            }
        }
    }

#ifdef DEBUG
    printf("dp: \n");
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            cout << dp[h][w] << " ";
        }
        cout << endl;
    }
    cout << endl;
#endif

    if (dp[0][0] > 0) {
        cout << "Takahashi" << endl;
    } else if (dp[0][0] < 0) {
        cout << "Aoki" << endl;
    } else {
        cout << "Draw" << endl;
    }

    return 0;
}
