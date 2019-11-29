#include <algorithm>
#include <iostream>
#include <list>
#include <map>
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

const int MAX_N = 100000;
const int MAX_M = 100000;
const int MAX_S = MAX_N + 1;

int N, M;
char S[MAX_S + 10];
vector<int> dp[MAX_S + 10];

bool solve(int prev, int cur) {
    while (cur >= 0) {
        while (S[cur] == '1') {
            cur--;
        }
        if (prev - cur > M) return false;

        if (dp[prev].front() + prev - cur <= M) {
            dp[cur] = dp[prev];
            dp[cur][0] += prev - cur;
        } else {
            dp[cur] = {prev - cur};
            dp[cur].insert(dp[cur].end(), dp[prev].begin(), dp[prev].end());
        }
        prev = cur;
        cur--;
    }

    return true;
}

int main(void) {
    cin >> N >> M;
    cin >> S;

    int prev;
    dp[N] = { 0 };
    for (int i = N - 1; i >= N - min(N, M); i--) {
        if (S[i] == '0') {
            prev = i;
            dp[i] = { N - i};
        }
    }

    if (solve(prev, N - min(N, M) - 1)) {
        for (auto &x : dp[0]) {
            cout << x << endl;
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}
