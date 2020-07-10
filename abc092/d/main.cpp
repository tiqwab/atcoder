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

const char WHITE = '.';
const char BLACK = '#';

vector<vector<char>> board;

int main(void) {
    int W, B;
    cin >> W >> B;

    const char HEIGHT = 100;
    const char WIDTH = 100;

    board.resize(HEIGHT, vector<char>(WIDTH));
    for (int h = 0; h < HEIGHT; h++) {
        for (int w = 0; w < WIDTH; w++) {
            if (h < HEIGHT / 2) {
                board[h][w] = WHITE;
            } else {
                board[h][w] = BLACK;
            }
        }
    }

    int black = 1;
    for (int h = 0; h < HEIGHT / 2 - 1; h += 2) {
        for (int w = (h % 2 == 0) ? 0 : 1; w < WIDTH; w += 2) {
            if (black < B) {
                board[h][w] = BLACK;
                black++;
            }
        }
    }

    int white = 1;
    for (int h = HEIGHT / 2 + 1; h < HEIGHT; h += 2) {
        for (int w = (h % 2 == 0) ? 0 : 1; w < WIDTH; w += 2) {
            if (white < W) {
                board[h][w] = WHITE;
                white++;
            }
        }
    }

    cout << 100 << " " << 100 << endl;
    for (int h = 0; h < HEIGHT; h++) {
        for (int w = 0; w < WIDTH; w++) {
            cout << board[h][w];
        }
        cout << endl;
    }

    return 0;
}
