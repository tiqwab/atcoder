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

const int WIN = 1;
const int LOSE = 0;

const int MOD = 7;

vector<vector<int>> dp;

// return true if Takahashi can win
bool solve(const int i, const int j, const int N, const string &S, const string &X) {
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    bool can_takahashi_win = true;
    const int d = S[i] - '0';

    if (X[i] == 'A') {
        // turn Aoki
        if (!solve(i + 1, (j * 10 + d) % MOD, N, S, X) || !solve(i + 1, (j * 10) % MOD, N, S, X)) {
            can_takahashi_win = false;
        }
    } else {
        // turn Takahashi
        if (!solve(i + 1, (j * 10 + d) % MOD, N, S, X) && !solve(i + 1, (j * 10) % MOD, N, S, X)) {
            can_takahashi_win = false;
        }
    }

    if (can_takahashi_win) {
        dp[i][j] = WIN;
    } else {
        dp[i][j] = LOSE;
    }

    return can_takahashi_win;
}

int main(void) {
    int N;
    cin >> N;
    string S;
    cin >> S;
    string X;
    cin >> X;

    dp.resize(N + 1, vector<int>(MOD, -1));
    dp[N][0] = WIN;
    for (int i = 1; i < MOD; i++) {
        dp[N][i] = LOSE;
    }

    bool ans = solve(0, 0, N, S, X);

#ifdef DEBUG
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < MOD; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
#endif

    if (ans) {
        cout << "Takahashi" << endl;
    } else {
        cout << "Aoki" << endl;
    }

    return 0;
}
