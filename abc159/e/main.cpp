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

vector<vector<int>> board;

int solve(const int H, const int W, const int K, const vector<int> yokos) {
    int ans = 0;

    vector<int> whites(H, 0);
    for (int i = 0; i < W; i++) {
        vector<int> cur_whites(H, 0);
        for (int j = 0; j < H; j++) {
            if (board[j][i] == 1) {
                cur_whites[j]++;
            }
        }

        bool needs_line = false;
        for (int j = 0; j < (int) yokos.size() - 1; j++) {
            int white_count = 0;
            int cur_white_count = 0;
            for (int k = yokos[j]; k < yokos[j + 1]; k++) {
                white_count += whites[k];
                cur_white_count += cur_whites[k];
                whites[k] += cur_whites[k];
            }

            // impossible if whites on one column > K
            if (cur_white_count > K) {
                return INF;
            }

            if (white_count + cur_white_count > K) {
                needs_line = true;
            }
        }
        if (needs_line) {
            ans++;
            whites = cur_whites;
        }

        // printf("whites: ");
        // for (int j = 0; j < H; j++) {
        //     printf("%d ", whites[j]);
        // }
        // printf("\n");

    }

    // printf("yokos: ");
    // for (auto &x : yokos) {
    //     printf("%d ", x);
    // }
    // printf(", ans: %d\n", ans);

    return ans;
}

int main(void) {
    int H, W, K;
    cin >> H >> W >> K;

    board.resize(H, vector<int>(W, 0));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char x;
            cin >> x;
            board[i][j] = (int) (x - '0');
        }
    }

    int ans = INF;
    for (int bits = 0; bits < (1 << (H - 1)); bits++) {
        vector<int> yokos;
        yokos.push_back(0);
        for (int i = 0; i < H; i++) {
            if (bits & (1 << i)) {
                yokos.push_back(i + 1);
            }
        }
        yokos.push_back(H);

        chmin(ans, solve(H, W, K, yokos) + ((int) yokos.size() - 2));
    }

    cout << ans << endl;

    return 0;
}
