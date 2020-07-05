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

const int MX = 100;
const int INF = INT_MAX / 2;

vector<vector<vector<int>>> dp;

void solve(const int A, const int B, const int C) {
    // {steps, a, b, c}
    queue<tuple<int, int, int, int>> que;
    dp[A][B][C] = 0;
    que.push(make_tuple(0, A, B, C));

    const vector<tuple<int, int, int>> diffs = {
        make_tuple(2, 0, 0),
        make_tuple(0, 2, 0),
        make_tuple(0, 0, 2),
        make_tuple(1, 1, 0),
        make_tuple(1, 0, 1),
        make_tuple(0, 1, 1),
    };

    while (!que.empty()) {
        auto elem = que.front();
        que.pop();
        int cur_steps, cur_a, cur_b, cur_c;
        tie(cur_steps, cur_a, cur_b, cur_c) = elem;
        // printf("cur_steps: %d, cur_a: %d, cur_b: %d, cur_c: %d\n",
        //         cur_steps, cur_a, cur_b, cur_c);

        for (auto &diff : diffs) {
            int diff_a, diff_b, diff_c;
            tie(diff_a, diff_b, diff_c) = diff;

            int next_steps = cur_steps + 1;
            int next_a = cur_a + diff_a;
            int next_b = cur_b + diff_b;
            int next_c = cur_c + diff_c;

            if (next_a >= MX || next_b >= MX || next_c >= MX) {
                continue;
            }

            if (next_steps < dp[next_a][next_b][next_c]) {
                dp[next_a][next_b][next_c] = next_steps;
                que.push(make_tuple(next_steps, next_a, next_b, next_c));
            }
        }
    }
}

// bfs
int main(void) {
    int A, B, C;
    cin >> A >> B >> C;

    dp.resize(MX);
    for (int i = 0; i < MX; i++) {
        dp[i].resize(MX);
        for (int j = 0; j < MX; j++) {
            dp[i][j].resize(MX, INF);
        }
    }

    solve(A, B, C);

    int ans = INF;
    for (int i = max({A, B, C}); i < MX; i++) {
        chmin(ans, dp[i][i][i]);
    }

    cout << ans << endl;

    return 0;
}
