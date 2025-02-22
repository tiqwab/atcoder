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

const vector<int> direction_h = {-1, 0, 1, 0};
const vector<int> direction_w = {0, 1, 0, -1};
const vector<char> snuke = {'s', 'n', 'u', 'k', 'e'};

bool dfs(const int h, const int w, const int steps, vector<vector<bool>> &visited, const int H, const int W, const vector<vector<char>> &board) {
    visited[h][w] = true;

#ifdef DEBUG
    printf("h: %d, w: %d\n", h, w);
#endif

    if (h == H - 1 && w == W - 1) {
        return true;
    }

    for (int i = 0; i < 4; i++) {
        int next_h = h + direction_h[i];
        int next_w = w + direction_w[i];
        if (next_h < 0 || next_h >= H || next_w < 0 || next_w >= W) {
            continue;
        }

        int next_steps = steps + 1;
        char expected_char = snuke[next_steps % ((int) snuke.size())];
        if (board[next_h][next_w] != expected_char) {
            continue;
        }
        if (visited[next_h][next_w]) {
            continue;
        }
        if (dfs(next_h, next_w, next_steps, visited, H, W, board)) {
            return true;
        }
    }

    return false;
}

int main(void) {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> board(H);
    for (int h = 0; h < H; h++) {
        string s;
        cin >> s;
        for (int w = 0; w < W; w++) {
            board[h].push_back(s[w]);
        }
    }

    if (board[0][0] != 's') {
        printf("No\n");
        return 0;
    }

    vector<vector<bool>> visited(H, vector<bool>(W, false));

    if (dfs(0, 0, 0, visited, H, W, board)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
