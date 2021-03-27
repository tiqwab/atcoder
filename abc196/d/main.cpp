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

int ans = 0;

void dfs(const int cur_pos, const int rem_a, const int rem_b, vector<vector<bool>> &used,
        const int H, const int W) {
    if (cur_pos == H * W) {
        if (rem_a == 0 && rem_b == 0) {
            ans++;
        }
        return;
    }

    const int cur_h = cur_pos / W;
    const int cur_w = cur_pos % W;

    // use B
    if (!used[cur_h][cur_w] && rem_b > 0) {
        used[cur_h][cur_w] = true;
        dfs(cur_pos + 1, rem_a, rem_b - 1, used, H, W);
        used[cur_h][cur_w] = false;
    }

    // use A yoko
    if (!used[cur_h][cur_w] && !used[cur_h][cur_w + 1] && rem_a > 0) {
        used[cur_h][cur_w] = true;
        used[cur_h][cur_w + 1] = true;
        dfs(cur_pos + 1, rem_a - 1, rem_b, used, H, W);
        used[cur_h][cur_w] = false;
        used[cur_h][cur_w + 1] = false;
    }

    // use A tate
    if (!used[cur_h][cur_w] && !used[cur_h + 1][cur_w] && rem_a > 0) {
        used[cur_h][cur_w] = true;
        used[cur_h + 1][cur_w] = true;
        dfs(cur_pos + 1, rem_a - 1, rem_b, used, H, W);
        used[cur_h][cur_w] = false;
        used[cur_h + 1][cur_w] = false;
    }

    dfs(cur_pos + 1, rem_a, rem_b, used, H, W);
}

int main(void) {
    int H, W, A, B;
    cin >> H >> W >> A >> B;

    vector<vector<bool>> used(H + 1, vector<bool>(W + 1, true));
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            used[h][w] = false;
        }
    }

    dfs(0, A, B, used, H, W);

    cout << ans << endl;

    return 0;
}
