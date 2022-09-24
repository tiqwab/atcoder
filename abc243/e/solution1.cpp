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

// from -> {to, cost}
vector<vector<pair<int, ll>>> edges;

set<pair<int, int>> necessary_edges;

void dijkstra(const int start, const int N) {
    vector<ll> dist(N, INF);
    dist[start] = 0;

    vector<int> prev(N);
    prev[start] = -1;

    vector<ll> steps(N, -INF);
    steps[start] = 0;

    auto f = [](const pair<int, ll>& one, const pair<int, ll>& other) {
        if (one.second != other.second) {
            return one.second > other.second;
        } else {
            return one.first > other.first;
        }
    };
    priority_queue<pair<int, ll>, vector<pair<int, ll>>, decltype(f)> q(f);
    q.push(make_pair(start, 0LL));

    while (!q.empty()) {
        const int cur_v = q.top().first;
        const ll cur_cost = q.top().second;
        q.pop();
        if (dist[cur_v] < cur_cost) {
            continue;
        }

        for (auto &edge : edges[cur_v]) {
            const int to = edge.first;
            const ll cost = edge.second;
            if (cur_cost + cost < dist[to]) {
                dist[to] = cur_cost + cost;
                q.push(make_pair(to, cur_cost + cost));
                prev[to] = cur_v;
                steps[to] = steps[cur_v] + 1;
            }
            if (cur_cost + cost == dist[to] && steps[cur_v] + 1 > steps[to]) {
                prev[to] = cur_v;
                steps[to] = steps[cur_v] + 1;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (i == start) {
            continue;
        }
        necessary_edges.insert(make_pair(i, prev[i]));
        necessary_edges.insert(make_pair(prev[i], i));
    }
}

int main(void) {
    int N, M;
    cin >> N >> M;

    edges.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges[a].push_back(make_pair(b, c));
        edges[b].push_back(make_pair(a, c));
    }

    for (int i = 0; i < N; i++) {
        dijkstra(i, N);
    }

#ifdef DEBUG
    printf("necessary_edges: \n");
    for (auto &edge : necessary_edges) {
        printf("(%d, %d)\n", edge.first, edge.second);
    }
#endif

    cout << M - ((int) necessary_edges.size() / 2) << endl;

    return 0;
}
