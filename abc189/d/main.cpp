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

const int MAX_N = 60;

// dp[i][0] = the number of the case when y_i is false
// dp[i][0] = the number of the case when y_i is true
vector<vector<ll>> dp;

vector<string> ss;

int main(void) {
    int N;
    cin >> N;

    ss.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> ss[i];
    }

    dp.resize(MAX_N + 1, vector<ll>(2, 0));
    dp[0][0] = 1;
    dp[0][1] = 1;

    for (int i = 0; i < N; i++) {
        string s = ss[i];
        if (s == "AND") {
            dp[i + 1][0] += dp[i][0] * 2 + dp[i][1];
            dp[i + 1][1] += dp[i][1];
        } else {
            dp[i + 1][0] += dp[i][0];
            dp[i + 1][1] += dp[i][0] + dp[i][1] * 2;
        }
    }

#ifdef DEBUG
    printf("dp: \n");
    for (int i = 0; i <= N; i++) {
        for (auto x : dp[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
    cout << endl;
#endif

    cout << dp[N][1] << endl;

    return 0;
}
