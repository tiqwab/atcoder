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

vector<int> problems;
vector<int> bonus;

int sum_score = 0;
vector<int> dp;

int solve(const int D, const ll G) {
    for (int i = 1; i <= D; i++) {
        for (int j = G; j >= 0; j--) {
            if (dp[j] != INF) {
                for (int k = 1; k <= problems[i]; k++) {
                    ll score = j + i * k;
                    if (score > G) {
                        score = G;
                    }
                    chmin(dp[score], dp[j] + k);
                    if (k == problems[i]) {
                        chmin(dp[min(G, score + bonus[i])], dp[j] + k);
                    }
                }
            }
        }
    }

    return dp[G];
}

int main(void) {
    int D;
    ll G;
    cin >> D >> G;
    G /= 100;

    problems.resize(D + 1);
    bonus.resize(D + 1);
    for (int i = 0; i < D; i++) {
        int p, c;
        cin >> p >> c;
        c /= 100;
        problems[i + 1] = p;
        bonus[i + 1] = c;
        sum_score += p * (i + 1);
        sum_score += c;
    }

    dp.resize(sum_score + 1, INF);
    dp[0] = 0;
    cout << solve(D, G) << endl;

    // for (int i = 0; i < (int) dp.size(); i++) {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;

    return 0;
}
