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

vector<vector<int>> edges;

vector<int> deps;

vector<int> dp;
vector<int> dp_max_price;

vector<bool> visited;

int dfs(const int cur) {
    int max_price = -INF;
    visited[cur] = true;
    for (auto to : edges[cur]) {
        if (dp_max_price[to] != -INF) {
            chmax(max_price, dp_max_price[to]);
        } else {
            chmax(max_price, dfs(to));
        }
    }
    dp[cur] = max_price - price[cur];
    dp_max_price[cur] = max(price[cur], max_price);
    return dp_max_price[cur];
}

int main(void) {
    int N, M;
    cin >> N >> M;

    price.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> price[i];
    }

    edges.resize(N);
    deps.resize(N);

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        edges[x].push_back(y);
        deps[y]++;
    }

    dp.resize(N, -INF);
    dp_max_price.resize(N, -INF);
    visited.resize(N, false);

    for (int i = 0; i < N; i++) {
        if (!visited[i] && deps[i] == 0) {
            dfs(i);
        }
    }

    int ans = -INF;
    for (int i = 0; i < N; i++) {
        chmax(ans, dp[i]);
    }
    cout << ans << endl;

    return 0;
}
