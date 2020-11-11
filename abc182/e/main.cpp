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

const int EMPTY = 0;
const int LIGHT = 1;
const int BLOCK = 2;

vector<vector<int>> board;

// h_obs[i] contains objects in h = i
vector<vector<int>> h_obs;
// w_obs[i] contains objects in w = i
vector<vector<int>> w_obs;

int solve(const int H, const int W) {
    int ans = 0;

    for (int h = 1; h <= H; h++) {
        for (int w = 1; w <= W; w++) {
            if (board[h][w] == LIGHT) {
                ans++;
                continue;
            } else if (board[h][w] == BLOCK) {
                continue;
            }

            auto it_h = lower_bound(h_obs[h].begin(), h_obs[h].end(), w);
            if (board[h][*it_h] == LIGHT) {
                ans++;
                continue;
            }
            if (board[h][*(it_h - 1)] == LIGHT) {
                ans++;
                continue;
            }

            auto it_w = lower_bound(w_obs[w].begin(), w_obs[w].end(), h);
            if (board[*it_w][w] == LIGHT) {
                ans++;
                continue;
            }
            if (board[*(it_w - 1)][w] == LIGHT) {
                ans++;
                continue;
            }
        }
    }

    return ans;
}

int main(void) {
    int H, W, N, M;
    cin >> H >> W >> N >> M;

    board.resize(H + 2, vector<int>(W + 2, EMPTY));
    for (int h = 0; h < H + 2; h++) {
        board[h][0] = BLOCK;
        board[h][W + 1] = BLOCK;
    }
    for (int w = 0; w < W + 2; w++) {
        board[0][w] = BLOCK;
        board[H + 1][w] = BLOCK;
    }

    h_obs.resize(H + 2, vector<int> {0, W + 1});
    w_obs.resize(W + 2, vector<int> {0, H + 1});

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        board[a][b] = LIGHT;
        h_obs[a].push_back(b);
        w_obs[b].push_back(a);
    }
    for (int i = 0; i < M; i++) {
        int c, d;
        cin >> c >> d;
        board[c][d] = BLOCK;
        h_obs[c].push_back(d);
        w_obs[d].push_back(c);
    }

    for (int i = 0; i <= H + 1; i++) {
        sort(h_obs[i].begin(), h_obs[i].end());
    }
    for (int i = 0; i <= W + 1; i++) {
        sort(w_obs[i].begin(), w_obs[i].end());
    }


#ifdef DEBUG
    printf("board: \n");
    for (int h = 0; h <= H + 1; h++) {
        for (int w = 0; w <= W + 1; w++) {
            printf("%d ", board[h][w]);
        }
        cout << endl;
    }
    cout << endl;
#endif

#ifdef DEBUG
    printf("h_obs: \n");
    for (int i = 0; i <= H + 1; i++) {
        for (auto x : h_obs[i]) {
            printf("%d, ", x);
        }
        cout << endl;
    }
    cout << endl;

    printf("w_obs: \n");
    for (int i = 0; i <= W + 1; i++) {
        for (auto x : w_obs[i]) {
            printf("%d, ", x);
        }
        cout << endl;
    }
    cout << endl;
#endif

    cout << solve(H, W) << endl;

    return 0;
}
