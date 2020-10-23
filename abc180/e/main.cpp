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

vector<int> xs;
vector<int> ys;
vector<int> zs;

// edges1[i][j] is cost from i to j
vector<vector<int>> edges1;

const int MAX_V = 17;
const ll INF = LONG_LONG_MAX / 2;

ll dp[(1 << MAX_V)][MAX_V];

ll solve(const int orig_bits, const int current, const int start,
        const int V, const vector<vector<int>> &edges) {
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
        chmin(min, solve(l, i, start, V, edges) + edge_cost);
        // cout << bitset<8>(l) << "," << current << "," << start << "," << i << "," << edge_cost << "," << min << endl;
    }

    dp[orig_bits][current] = min;
    return dp[orig_bits][current];
}

int main(void) {
    int N;
    cin >> N;

    xs.resize(N);
    ys.resize(N);
    zs.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> xs[i] >> ys[i] >> zs[i];
    }

    edges1.resize(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }
            edges1[i][j] = abs(xs[j] - xs[i]) + abs(ys[j] - ys[i]) + max(0, zs[j] - zs[i]);
        }
    }
#ifdef DEBUG
    printf("edges1: \n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << edges1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
#endif

    for (int i = 0; i < (1 << MAX_V); i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }

    ll ans = solve(0, 0, 0, N, edges1);
    cout << ans << endl;

    return 0;
}
