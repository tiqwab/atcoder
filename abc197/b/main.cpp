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

vector<int> dir_x = {1, 0, -1, 0};
vector<int> dir_y = {0, 1, 0, -1};

int main(void) {
    int H, W, X, Y;
    cin >> H >> W >> X >> Y;
    X--;
    Y--;
    swap(X, Y);

    vector<vector<char>> board(H, vector<char>(W));

    for (int h = 0; h < H; h++) {
        string S;
        cin >> S;
        for (int w = 0; w < W; w++) {
            const char c = S[w];
            board[h][w] = c;
        }
    }

#ifdef DEBUG
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            cout << board[h][w];
        }
        cout << endl;
    }
    cout << endl;
#endif

    int ans = 1;

    for (int i = 0; i < 4; i++) {
        const int diff_x = dir_x[i];
        const int diff_y = dir_y[i];
        int cur_x = X + diff_x;
        int cur_y = Y + diff_y;
#ifdef DEBUG
            printf("y=%d x=%d\n", cur_y, cur_x);
#endif
        while (cur_x >= 0 && cur_x < W && cur_y >= 0 && cur_y < H) {
            if (board[cur_y][cur_x] == '#') {
                break;
            }
#ifdef DEBUG
            printf("ok y=%d x=%d\n", cur_y, cur_x);
#endif
            ans++;
            cur_x += diff_x;
            cur_y += diff_y;
        }
    }

    cout << ans << endl;

    return 0;
}
