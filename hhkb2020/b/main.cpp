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

const int MAX_H = 100;
const int MAX_W = 100;

vector<vector<char>> board;

int main(void) {
    int H, W;
    cin >> H >> W;

    board.resize(MAX_H + 1, vector<char>(MAX_W + 1, '#'));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c;
            cin >> c;
            if (c == '.') {
                board[i][j] = '.';
            }
        }
    }

    int cnt = 0;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (board[h][w] == '.' && board[h][w + 1] == '.') {
                cnt++;
            }
        }
    }
    for (int w = 0; w < W; w++) {
        for (int h = 0; h < H; h++) {
            if (board[h][w] == '.' && board[h + 1][w] == '.') {
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
