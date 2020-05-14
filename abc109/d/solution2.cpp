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

typedef pair<int, int> point;

int H, W;
vector<vector<int>> board;

vector<pair<point, point>> ans;

int main(void) {
    cin >> H >> W;

    board.resize(H, vector<int>(W, 0));
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            cin >> board[h][w];
        }
    }

    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W - 1; w++) {
            if (board[h][w] % 2 == 1) {
                ans.push_back({{h, w}, {h, w + 1}});
                board[h][w]--;
                board[h][w + 1]++;
            }
        }
    }
    for (int h = 0; h < H - 1; h++) {
        if (board[h][W - 1] % 2 == 1) {
            ans.push_back({{h, W - 1}, {h + 1, W - 1}});
            board[h][W - 1]--;
            board[h + 1][W - 1]++;
        }
    }

    printf("%d\n", (int) ans.size());
    for (auto &path : ans) {
        auto from = path.first;
        auto to = path.second;
        printf("%d %d %d %d\n", from.first + 1, from.second + 1, to.first + 1, to.second + 1);
    }

    return 0;
}
