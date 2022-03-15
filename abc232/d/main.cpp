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

vector<vector<char>> board;
vector<vector<bool>> visited;

void dfs(const int cur_h, const int cur_w, const int H, const int W) {
    visited[cur_h][cur_w] = true;
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}};

    for (auto dir : dirs) {
        const int next_h = cur_h + dir.first;
        const int next_w = cur_w + dir.second;
        if (next_h >= H || next_w >= W || board[next_h][next_w] == '#') {
            continue;
        }
        if (visited[next_h][next_w]) {
            continue;
        }
        dfs(next_h, next_w, H, W);
    }
}

int main(void) {
    int H, W;
    cin >> H >> W;

    board.resize(H, vector<char>(W, '#'));
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            char c;
            cin >> c;
            board[h][w] = c;
        }
    }

    visited.resize(H, vector<bool>(W, false));

    dfs(0, 0, H, W);

    int ans = 1;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (visited[h][w]) {
                chmax(ans, h + w + 1);
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}
