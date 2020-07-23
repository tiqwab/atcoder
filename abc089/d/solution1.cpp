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
// required magic from a to b

// {y, x}
vector<pair<int, int>> n_to_pos;

vector<vector<ll>> memo;

void prepare(const int H, const int W, const int D) {
    memo.resize(D);
    for (int i = 0; i < D; i++) {
        memo[i].push_back(0);
        memo[i].push_back(0);
        for (int j = i + D; j <= H * W; j += D) {
            int cur = j;
            int prev = j - D;

            if (j == D) {
                continue;
            }

            pair<int, int> cur_pos = n_to_pos[cur];
            pair<int, int> prev_pos = n_to_pos[prev];
            ll cost = memo[i][(int) memo[i].size() - 1]
                + abs(cur_pos.first - prev_pos.first) + abs(cur_pos.second - prev_pos.second);
            memo[i].push_back(cost);
        }
    }
}

ll solve(const int L, const int R, const int H, const int W, const int D) {
    const int rem = L % D;
    const int ind_L = (L + D - 1) / D;
    const int ind_R = (R + D - 1) / D;
    return memo[rem][ind_R] - memo[rem][ind_L];

    // ll ans = 0;
    // for (int i = L; i < R; i+= D) {
    //     int cur = i;
    //     int next = i + D;
    //     pair<int, int> cur_pos = n_to_pos[cur];
    //     pair<int, int> next_pos = n_to_pos[next];
    //     ans += abs(cur_pos.first - next_pos.first) + abs(cur_pos.second - next_pos.second);
    // }
    // return ans;
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
    // for (auto a : memo) {
    //     for (auto b : a) {
    //         cout << b << " ";
    //     }
    //     cout << endl;
    // }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;
        cout << solve(L, R, H, W, D) << endl;
    }

    return 0;
}
