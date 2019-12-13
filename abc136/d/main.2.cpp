#include <algorithm>
#include <iostream>
#include <vector>

#include <string.h>

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

const int MAX_S = 100000;
char S[MAX_S + 1];

void solve(const int N) {
    // dp[i][j] is position after 2^i moving from start position j.
    vector<vector<int> > dp(32, vector<int>(N));

    // move one step
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') {
            dp[0][i] = i + 1;
        } else {
            dp[0][i] = i - 1;
        }
    }

    for (int i = 1; i < 32; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }

    vector<int> last_positions(N, 0);
    for (int i = 0; i < N; i++) {
        last_positions[i] = i;
    }

    // 10^5 = 2^5 + 2 ^7 + 2^9 + 2^10 + 2^15 + 2^16
    vector<int> as = {5, 7, 9, 10, 15, 16};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (int) as.size(); j++) {
            last_positions[i] = dp[as[j]][last_positions[i]];
        }
    }

    vector<int> answer(N);
    for (int i = 0; i < N; i++) {
        answer[last_positions[i]]++;
    }

    cout << answer[0];
    for (int i = 1; i < N; i++) {
        cout << " " << answer[i];
    }
    cout << endl;
}

/*
 * DP solution.
 * ref. https://img.atcoder.jp/abc136/editorial.pdf
 */
int main(void) {
    cin >> S;
    int N = strlen(S);

    solve(N);

    return 0;
}
