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
// {diff_y, diff_x} of up, right, down, and left
const vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

vector<vector<char>> board;
vector<vector<int>> dist;

void dfs(const int cur_h, const int cur_w, const int cur_d) {
    dist[cur_h][cur_w] = cur_d;

    for (auto dir : dirs) {
        const int next_h = cur_h + dir.first;
        const int next_w = cur_w + dir.second;
        if (board[next_h][next_w] != '#' && dist[next_h][next_w] > cur_d + 1) {
            dfs(next_h, next_w, cur_d + 1);
        }
    }
}

int main(void) {
    int H, W;
    cin >> H >> W;

    int n_black = 0;

    board.resize(H + 2, vector<char>(W + 2, '#'));
    for (int h = 1; h <= H; h++) {
        for (int w = 1; w <= W; w++) {
            cin >> board[h][w];
            if (board[h][w] == '#') {
                n_black++;
            }
        }
    }

    dist.resize(H + 2, vector<int>(W + 2, INF));
    dfs(1, 1, 0);

    // for (int h = 1; h <= H; h++) {
    //     for (int w = 1; w <= W; w++) {
    //         cout << dist[h][w] << " ";
    //     }
    //     cout << endl;
    // }

    if (dist[H][W] != INF) {
        cout << H * W - n_black - (dist[H][W] + 1) << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
