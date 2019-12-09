#include <algorithm>
#include <cassert>
#include <iostream>
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

typedef vector<vector<pair<int, int> > > Edges;

const int MAX_V = 15;
const ll INF = LONG_LONG_MAX / 2;

ll dp[(1 << MAX_V)][MAX_V];

ll solve(const int orig_bits, const int last_v, const int V, const int E, const Edges &edges) {
    assert(orig_bits & (1 << last_v));

    if (dp[orig_bits][last_v] != INF) {
        return dp[orig_bits][last_v];
    }

    if ((orig_bits & (orig_bits - 1)) == 0) {
        // there is only one bit
        dp[orig_bits][last_v] = 0;
        return dp[orig_bits][last_v];
    }

    ll min = INF;
    int bits = orig_bits & (~(1 << last_v));
    for (int i = 0; i < V; i++) {
        int k = 1 << i;
        int l = (bits & ~k);
        if (l == bits) continue;

        ll edge_cost = INF;
        for (int j = 0; j < (int) edges[i].size(); j++) {
            if (edges[i][j].first == last_v) {
                edge_cost = edges[i][j].second;
            }
        }
        chmin(min, solve(bits, i, V, E, edges) + edge_cost);
        // cout << orig_bits << "," << last_v << "," << i << "," << edge_cost << "," << min << endl;
    }

    dp[orig_bits][last_v] = min;
    return dp[orig_bits][last_v];
}

/*
 * https://qiita.com/drken/items/7c6ff2aa4d8fce1c9361#%E5%B7%A1%E5%9B%9E%E3%82%BB%E3%83%BC%E3%83%AB%E3%82%B9%E3%83%9E%E3%83%B3%E5%95%8F%E9%A1%8C
 */
int main(void) {
    int V, E;
    cin >> V >> E;

    Edges edges(V);
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        edges[s].push_back({t, d});
        edges[t].push_back({s, d});
    }

    for (int i = 0; i < (1 << MAX_V); i++) {
        for (int j = 0;j < MAX_V; j++) {
            dp[i][j] = INF;
        }
    }

    ll min = INF;
    for (int i = 0; i < V; i++) {
        chmin(min, solve((1 << V) - 1, i, V, E, edges));
    }
    cout << min << endl;
    
    return 0;
}
