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

const ll INF = LONG_LONG_MAX / 2;

struct Edge {
    int from;
    int to;
    int score;
};

vector<struct Edge> edges;
vector<vector<int>> edges_from_start;
vector<vector<int>> edges_from_goal;

vector<bool> reachable;
vector<bool> reachable_from_start;
vector<bool> reachable_to_goal;

vector<ll> scores;

ll bellman_ford(const int N) {
    for (int i = 0; i < N; i++) {
        for (auto &edge : edges) {
            int u = edge.from;
            int v = edge.to;
            int c = edge.score;

            if (!reachable[u]) continue;
            if (!reachable[v]) continue;

            if (scores[v] > scores[u] + c) {
                scores[v] = scores[u] + c;
            }
        }
    }

    for (auto &edge : edges) {
        int u = edge.from;
        int v = edge.to;
        int c = edge.score;

        if (!reachable[u]) continue;
        if (!reachable[v]) continue;

        if (scores[v] > scores[u] + c) {
            return -INF;
        }
    }

    return scores[N - 1];
}

void dfs(const int cur, vector<bool> &my_reachable, const vector<vector<int>> &my_edges) {
    if (my_reachable[cur]) {
        return;
    }
    my_reachable[cur] = true;
    for (auto &next : my_edges[cur]) {
        dfs(next, my_reachable, my_edges);
    }
}

void check_reachable(const int N) {
    dfs(0, reachable_from_start, edges_from_start);
    dfs(N - 1, reachable_to_goal, edges_from_goal);
    for (int i = 0; i < N; i++) {
        reachable[i] = reachable_from_start[i] && reachable_to_goal[i];
    }
}

int main(void) {
    int N, M, P;
    cin >> N >> M >> P;

    edges.resize(N);
    edges_from_start.resize(N);
    edges_from_goal.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;

        c -= P;
        c *= -1;
        edges.push_back({a, b, c});

        edges_from_start[a].push_back(b);
        edges_from_goal[b].push_back(a);
    }

    reachable.resize(N, false);
    reachable_from_start.resize(N, false);
    reachable_to_goal.resize(N, false);
    check_reachable(N);

    scores.resize(N, INF);
    scores[0] = 0;
    ll ans = bellman_ford(N);
    if (ans == -INF) {
        cout << -1 << endl;
    } else if (ans <= 0) {
        cout << -1 * ans << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
