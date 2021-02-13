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

// {to, cost}
vector<vector<pair<int, int>>> edges;

int do_dijkstra(const int start, const int N) {
    vector<int> dists(N, INF);

    // {town, cost}
    auto f = [](const pair<int, int>& one, const pair<int, int>& other) {
        if (one.second != other.second) {
            return one.second > other.second;
        } else {
            return one.first > other.first;
        }
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(f)> q(f);

    for (auto &edge :edges[start]) {
        const int to = edge.first;
        const int cost = edge.second;
        if (cost < dists[to]) {
            dists[to] = cost;
            q.push(make_pair(to, cost));
        }
    }

    while (!q.empty()) {
        const int cur_town = q.top().first;
        const int cur_cost = q.top().second;
        q.pop();
        if (dists[cur_town] < cur_cost) {
            continue;
        }

        for (auto &edge : edges[cur_town]) {
            const int to = edge.first;
            const int cost = edge.second;
            if (cur_cost + cost < dists[to]) {
                dists[to] = cur_cost + cost;
                q.push(make_pair(to, dists[to]));
            }
        }
    }

    return dists[start] != INF ? dists[start] : -1;
}

int main(void) {
    int N, M;
    cin >> N >> M;

    edges.resize(N);
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        A--;
        B--;
        edges[A].push_back(make_pair(B, C));
    }

    for (int i = 0; i < N; i++) {
        int ans = do_dijkstra(i, N);
        printf("%d\n", ans);
    }

    return 0;
}
