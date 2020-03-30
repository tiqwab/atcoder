#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

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

const int MAX_DIFF = (80 + 80) * 80;

vector<vector<int>> A;
vector<vector<int>> B;

vector<vector<vector<bool>>> dp;

void solve(const int H, const int W) {
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            const int diff = abs(A[i][j] - B[i][j]);
            // up
            {
                const vector<bool> &xs = dp[i - 1][j];
                for (int k = 0; k < (int) xs.size(); k++) {
                    if (xs[k]) {
                        dp[i][j][abs(k + diff)] = true;
                        dp[i][j][abs(k - diff)] = true;
                    }
                }
            }

            // left
            {
                const vector<bool> &xs = dp[i][j - 1];
                for (int k = 0; k < (int) xs.size(); k++) {
                    if (xs[k]) {
                        dp[i][j][abs(k + diff)] = true;
                        dp[i][j][abs(k - diff)] = true;
                    }
                }
            }
        }
    }
}

int main(void) {
    int H, W;
    cin >> H >> W;

    A.resize(H + 1, vector<int>(W + 1, 0));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int x;
            cin >> x;
            A[i + 1][j + 1] = x;
        }
    }

    B.resize(H + 1, vector<int>(W + 1, 0));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int x;
            cin >> x;
            B[i + 1][j + 1] = x;
        }
    }

    dp.resize(H + 2);
    for (int i = 0; i < H + 2; i++) {
        dp[i].resize(W + 2);
        for (int j = 0; j < W + 2; j++) {
            dp[i][j].resize(MAX_DIFF + 1, false);
        }
    }

    dp[0][0][0] = true;
    dp[1][0][0] = true;
    dp[0][1][0] = true;
    solve(H, W);

    for (int i = 0; i < (int) dp[H][W].size(); i++) {
        if (dp[H][W][i]) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
