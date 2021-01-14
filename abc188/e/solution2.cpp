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

vector<int> price;

// from[i] is destination towns from town i
vector<vector<int>> from;

// to[i] is departure towns to town i
vector<vector<int>> to;

// deps[i] is how many roads the town i has (as a starting place)
vector<int> deps;

// dp[i] is the maximum profit when Takahashi buys gold at town i
vector<int> dp;

int main(void) {
    int N, M;
    cin >> N >> M;

    price.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> price[i];
    }

    from.resize(N);
    to.resize(N);
    deps.resize(N);

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        from[x].push_back(y);
        to[y].push_back(x);
        deps[x]++;
    }

    dp.resize(N, -INF);

    // towns whose deps == 0
    queue<int> q;

    for (int i = 0; i < N; i++) {
        if (deps[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        auto cur_town = q.front();
        q.pop();

        int cand = -INF;

        for (auto dest : from[cur_town]) {
            chmax(cand, price[dest] - price[cur_town]);
            if (dp[dest] != -INF) {
                chmax(cand, dp[dest] + price[dest] - price[cur_town]);
            }
        }

        dp[cur_town] = cand;

        for (auto other : to[cur_town]) {
            deps[other]--;
            if (deps[other] == 0) {
                q.push(other);
            }
        }
    }

    int ans = -INF;
    for (int i = 0; i < N; i++) {
        chmax(ans, dp[i]);
    }
    cout << ans << endl;

    return 0;
}
