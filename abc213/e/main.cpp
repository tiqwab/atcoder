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

const int INF = INT_MAX / 2;
const char BLOCK = '#';
const char EMPTY = '.';

const vector<int> dir_h = {-1, 0, 1, 0};
const vector<int> dir_w = {0, 1, 0, -1};

vector<vector<char>> board;
vector<vector<int>> memo;

int main(void) {
    int H, W;
    cin >> H >> W;

    board.resize(H, vector<char>(W, BLOCK));
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            char c;
            cin >> c;
            board[h][w] = c;
        }
    }

    memo.resize(H, vector<int>(W, INF));
    memo[0][0] = 0;

    // {h, w, dist}
    deque<tuple<int, int, int>> q;
    q.push_front(make_tuple(0, 0, 0));

    while (!q.empty()) {
        int cur_h, cur_w, cur_dist;
        tie(cur_h, cur_w, cur_dist) = q.front();
        q.pop_front();
        if (cur_dist > memo[cur_h][cur_w]) {
            continue;
        }

        // walk without punch
        for (int i = 0; i < 4; i++) {
            int next_h = cur_h + dir_h[i];
            int next_w = cur_w + dir_w[i];
            int next_dist = cur_dist;

            if (next_h < 0 || next_h >= H || next_w < 0 || next_w >= W) {
                continue;
            }
            if (board[next_h][next_w] == BLOCK) {
                continue;
            }
            if (next_dist < memo[next_h][next_w]) {
                memo[next_h][next_w] = next_dist;
                q.push_front(make_tuple(next_h, next_w, next_dist));
            }
        }

        // walk with punch
        for (int diff_h = -2; diff_h < 3; diff_h++) {
            for (int diff_w = -2; diff_w < 3; diff_w++) {
                if (abs(diff_h) == 2 && abs(diff_w) == 2) {
                    continue;
                }

                int next_h = cur_h + diff_h;
                int next_w = cur_w + diff_w;
                int next_dist = cur_dist + 1;

                if (next_h < 0 || next_h >= H || next_w < 0 || next_w >= W) {
                    continue;
                }

                if (next_dist < memo[next_h][next_w]) {
                    memo[next_h][next_w] = next_dist;
                    q.push_back(make_tuple(next_h, next_w, next_dist));
                }
            }
        }
    }

    cout << memo[H - 1][W - 1] << endl;

    return 0;
}
