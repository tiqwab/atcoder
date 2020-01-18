#include <algorithm>
#include <iostream>
#include <queue>
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

// descending order base on costs
auto compare = [](const pair<int, int> &x, const pair<int, int> &y) {
    return x.second > y.second;
};
typedef priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> PriorityQueue;

// {dest, cost}
vector<vector<pair<int, int>>> edges;
vector<bool> visited;

ll solve(PriorityQueue q) {
    ll acc = 0;

    while (!q.empty()) {
        pair<int, int> edge = q.top();
        int dest = edge.first;
        int cost = edge.second;
        q.pop();
        if (visited[dest]) continue;

        visited[dest] = true;
        acc += cost;
        for (int i = 0; i < (int) edges[dest].size(); i++) {
            q.push(edges[dest][i]);
        }
    }

    return acc;
}

// Calculate minimum spanning tree by Prim method.
// time complexity: O(E * log(V))
// ref. http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp
int main(void) {
    int V, E;
    cin >> V >> E;

    edges.resize(V);
    for (int i = 0; i < E; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        edges[s].push_back({t, w});
        edges[t].push_back({s, w});
    }

    visited.resize(V, false);
    visited[0] = true;

    PriorityQueue q(compare);
    for (int i = 0; i < (int) edges[0].size(); i++) {
        q.push(edges[0][i]);
    }

    cout << solve(q) << endl;

    return 0;
}
