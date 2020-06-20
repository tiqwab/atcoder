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

int main(void) {
    int H, W;
    cin >> H >> W;

    board.resize(H + 2, vector<char>(W + 2, '.'));
    for (int h = 1; h <= H; h++) {
        for (int w = 1; w <= W; w++) {
            char c;
            cin >> c;
            if (c == '#') {
                board[h][w] = c;
            }
        }
    }

    bool ok = true;
    for (int h = 1; h <= H; h++) {
        for (int w = 1; w <= W; w++) {
            if (board[h][w] == '#') {
                if (board[h - 1][w] == '.' && board[h + 1][w] == '.'
                        && board[h][w - 1] == '.' && board[h][w + 1] == '.') {
                    ok = false;
                }
            }
        }
    }

    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
