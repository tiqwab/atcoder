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

const int MAX_X = 10000;

int main(void) {
    int N, X;
    cin >> N >> X;

    vector<int> as, bs;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        as.push_back(a);
        bs.push_back(b);
    }

    vector<vector<bool>> dp(N + 1, vector<bool>(MAX_X + 1, false));
    dp[0][0] = true;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < MAX_X; j++) {
            if (!dp[i][j]) {
                continue;
            }
            if (j + as[i] <= MAX_X) {
                dp[i + 1][j + as[i]] = true;
            }
            if (j + bs[i] <= MAX_X) {
                dp[i + 1][j + bs[i]] = true;
            }
        }
    }

    if (dp[N][X]) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
