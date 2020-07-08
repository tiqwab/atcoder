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

int solve(const int all_bk, const int H, const int W, const int K) {
    int ans = 0;

    for (int h_bits = 0; h_bits < (1 << H); h_bits++) {
        for (int w_bits = 0; w_bits < (1 << W); w_bits++) {
            int cnt = 0;
            for (int h = 0; h < H; h++) {
                for (int w = 0; w < W; w++) {
                    if (board[h][w] == '#') {
                        if ((h_bits & (1 << h)) || (w_bits & (1 << w))) {
                            cnt++;
                        }
                    }
                }
            }

            if (all_bk - cnt == K) {
                ans++;
            }
        }
    }

    return ans;
}

int main(void) {
    int H, W, K;
    cin >>  H >> W >> K;

    int all_bk = 0;

    board.resize(H, vector<char>(W));
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            char c;
            cin >> c;
            board[h][w] = c;
            if (c == '#') {
                all_bk++;
            }
        }
    }

    cout << solve(all_bk, H, W, K) << endl;

    return 0;
}
