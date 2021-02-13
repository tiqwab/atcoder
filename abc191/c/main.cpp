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

    board.resize(H, vector<char>(W));
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            char c;
            cin >> c;
            board[h][w] = c;
        }
    }

    int ans = 0;

    auto f = [&](const char prev, const char cur) {
        for (int h = 1; h < H; h++) {
            bool filled = false;
            for (int w = 0; w < W; w++) {
                if (filled) {
                    if (board[h - 1][w] == prev && board[h][w] == cur) {
                        // do nothing
                    } else {
                        filled = false;
                        ans += 2;
                    }
                } else {
                    if (board[h - 1][w] == prev && board[h][w] == cur) {
                        filled = true;
                    } else {
                        // do nothing
                    }
                }
            }
        }
    };

    // w -> b
    f('.', '#');
    // b -> w
    f('#', '.');

    cout << ans << endl;

    return 0;
}
