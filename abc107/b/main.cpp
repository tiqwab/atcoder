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

// 1: white, 2: black, 3: removed
vector<vector<int>> board;

int main(void) {
    int H, W;
    cin >> H >> W;

    board.resize(H, vector<int>(W));
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            char a;
            cin >> a;
            if (a == '#') {
                board[h][w] = 2;
            } else {
                board[h][w] = 1;
            }
        }
    }

    for (int h = 0; h < H; h++) {
        bool should_remove = true;
        for (int w = 0; w < W; w++) {
            if (board[h][w] == 2) {
                should_remove = false;
            }
        }
        if (should_remove) {
            for (int w = 0; w < W; w++) {
                board[h][w] = 3;
            }
        }
    }

    for (int w = 0; w < W; w++) {
        bool should_remove = true;
        for (int h = 0; h < H; h++) {
            if (board[h][w] == 2) {
                should_remove = false;
            }
        }
        if (should_remove) {
            for (int h = 0; h < H; h++) {
                board[h][w] = 3;
            }
        }
    }

    for (int h = 0; h < H; h++) {
        bool emitted = false;
        for (int w = 0; w < W; w++) {
            if (board[h][w] == 1) {
                emitted = true;
                cout << '.';
            } else if (board[h][w] == 2) {
                emitted = true;
                cout << '#';
            }
        }
        if (emitted) {
            cout << endl;
        }
    }

    return 0;
}
