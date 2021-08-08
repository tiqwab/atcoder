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

const vector<int> dir_h = {-1, 0, 1, 0};
const vector<int> dir_w = {0, 1, 0, -1};

vector<vector<char>> board;

int ans = 0;

void print_board(const int H, const int W) {
    printf("board: \n");
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            cout << board[h][w] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void dfs(const int K, const int H, const int W) {
    int cnt = 0;

    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (board[h][w] == 'o') {
                cnt++;
            }
        }
    }

    if (cnt == K) {
#ifdef DEBUG
        print_board(H, W);
#endif
        ans++;
        return;
    }

    for (int cur_h = 0; cur_h < H; cur_h++) {
        for (int cur_w = 0; cur_w < W; cur_w++) {
            if (board[cur_h][cur_w] != '.') {
                continue;
            }

            if (cnt > 0) {
                bool ok = false;

                for (int i = 0; i < 4; i++) {
                    const int neigh_h = cur_h + dir_h[i];
                    const int neigh_w = cur_w + dir_w[i];
                    if (neigh_h < 0 || neigh_h >= H || neigh_w < 0 || neigh_w >= W) {
                        continue;
                    }

                    if (board[neigh_h][neigh_w] == 'o') {
                        ok = true;
                    }
                }

                if (!ok) {
                    continue;
                }
            }

            board[cur_h][cur_w] = 'o';
            dfs(K, H, W);
            board[cur_h][cur_w] = '#';
            dfs(K, H, W);
            if (cnt > 0) {
                board[cur_h][cur_w] = '.';
            }
            return;
        }
    }
}

int main(void) {
    int N, K;
    cin >> N >> K;

    board.resize(N, vector<char>(N, ' '));
    for (int h = 0; h < N; h++) {
        for (int w = 0; w < N; w++) {
            char c;
            cin >> c;
            board[h][w] = c;
        }
    }

    dfs(K, N, N);

    cout << ans << endl;

    return 0;
}
