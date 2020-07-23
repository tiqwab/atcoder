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

vector<vector<int>> board;

// {y, x}
vector<pair<int, int>> n_to_pos;

vector<int> memo;

void prepare(const int H, const int W, const int D) {
    memo.resize(H * W + 1, 0);
    for (int i = D + 1; i <= H * W; i++) {
        pair<int, int> cur_pos = n_to_pos[i];
        pair<int, int> prev_pos = n_to_pos[i - D];
        int cost = memo[i - D]
            + abs(cur_pos.first - prev_pos.first) + abs(cur_pos.second - prev_pos.second);
        memo[i] = cost;
    }
}

int solve(const int L, const int R) {
    return memo[R] - memo[L];
}

int main(void) {
    int H, W, D;
    cin >> H >> W >> D;

    board.resize(H, vector<int>(W));
    n_to_pos.resize(H * W + 1);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> board[i][j];
            n_to_pos[board[i][j]] = {i, j};
        }
    }

    prepare(H, W, D);

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;
        cout << solve(L, R) << endl;
    }

    return 0;
}
