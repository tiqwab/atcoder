#include <algorithm>
#include <bitset>
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

const int MAX_V = 15;
const ll INF = LONG_LONG_MAX / 2;

typedef ll Edges[MAX_V][MAX_V];

Edges edges;
ll dp[(1 << MAX_V)][MAX_V];

ll solve(const int orig_bits, const int current, const int start, const int V, const int E) {
    if (dp[orig_bits][current] != -1) {
        return dp[orig_bits][current];
    }

    if (((orig_bits == (1 << V) - 1)) && (current == start)) {
        // cout << "come here" << endl;
        dp[(1 << V) - 1][current] = 0;
        return 0;
    }

    ll min = INF;
    for (int i = 0; i < V; i++) {
        int l = orig_bits | (1 << i);
        if (l == orig_bits) continue;

        ll edge_cost = edges[current][i];
        if (edge_cost == INF) {
            continue;
        }
        chmin(min, solve(l, i, start, V, E) + edge_cost);
        // cout << bitset<8>(l) << "," << current << "," << start << "," << i << "," << edge_cost << "," << min << endl;
    }

    dp[orig_bits][current] = min;
    return dp[orig_bits][current];
}

/*
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A&lang=jp
 * https://dalekspritner.hatenablog.com/entry/2018/09/27/231030
 */
int main(void) {
    int V, E;
    cin >> V >> E;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            edges[i][j] = INF;
        }
    }
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        edges[s][t] = d;
    }

    for (int i = 0; i < (1 << MAX_V); i++) {
        for (int j = 0;j < MAX_V; j++) {
            dp[i][j] = -1;
        }
    }

    ll ans = solve(0, 0, 0, V, E);
    if (ans != INF) {
        cout << ans << endl;
    } else {
        cout << "-1" << endl;
    }
    
    return 0;
}
