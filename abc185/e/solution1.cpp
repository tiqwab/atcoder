#include <algorithm>
#include <iostream>
#include <vector>

#include <string.h>
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

const int MAX_S = 1000;

int dp[MAX_S + 1][MAX_S + 1];

int solve(const vector<int> &s1, const int l1, const vector<int> &s2, const int l2) {
    for (int i = 0; i <= l1; i++) {
        dp[i][0] = i;
        for (int j = 1; j <= l2; j++) {
            if (i == 0) {
                dp[i][j] = j;
                continue;
            }
            if (s1[i - 1] == s2[j - 1]) {
                chmin(dp[i][j], dp[i - 1][j - 1]);
            } else {
                chmin(dp[i][j], dp[i - 1][j - 1] + 1);
            }
            chmin(dp[i][j], dp[i - 1][j] + 1);
            chmin(dp[i][j], dp[i][j - 1] + 1);
        }
    }
    return dp[l1][l2];
}

vector<int> as;
vector<int> bs;

int main(void) {
    int N, M;
    cin >> N >> M;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    bs.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> bs[i];
    }

    reverse(as.begin(), as.end());
    reverse(bs.begin(), bs.end());

    for (int i = 0; i < MAX_S + 1; i++) {
        for (int j = 0; j < MAX_S + 1; j++) {
            dp[i][j] = INT_MAX / 2;
        }
    }

    if (N < M) {
        cout << solve(as, N, bs, M) << endl;
    } else {
        cout << solve(bs, M, as, N) << endl;
    }
    
    return 0;
}
