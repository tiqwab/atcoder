#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <cmath>

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

typedef struct Edge {
    int to;
    int c;
    int d;
} Edge;

vector<vector<Edge>> edges;

ll solve(const int N) {
    vector<ll> dist(N, INF);

    // {city, time}
    auto f = [](const pair<int, ll>& one, const pair<int, ll>& other) {
        if (one.second != other.second) {
            return one.second > other.second;
        } else {
            return one.first > other.first;
        }
    };
    priority_queue<pair<int, ll>, vector<pair<int, ll>>, decltype(f)> q(f);

    dist[0] = 0;
    q.push(make_pair(0, 0));

    while (!q.empty()) {
        auto elem = q.top();
        q.pop();
        const int cur_city = elem.first;
        const ll cur_time = elem.second;
        if (dist[cur_city] < cur_time) {
            continue;
        }

        for (auto edge : edges[cur_city]) {
            ll cand_min_time = cur_time + edge.c + edge.d / (cur_time + 1);

            ll t = (ll) sqrt(edge.d);
            for (int i = -3; i <= 3; i++) {
                ll u = t + i;
                if (u > cur_time) {
                    chmin(cand_min_time, u + edge.c + edge.d / (u + 1));
                }
            }

            if (cand_min_time < dist[edge.to]) {
                dist[edge.to] = cand_min_time;
                q.push(make_pair(edge.to, cand_min_time));
            }
        }
    }

    return dist[N - 1];
}

int main(void) {
    int N, M;
    cin >> N >> M;

    edges.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        edges[a].push_back(Edge{b, c, d});
        edges[b].push_back(Edge{a, c, d});
    }

    ll ans = solve(N);
    if (ans == INF) {
        ans = -1;
    }
    cout << ans << endl;

    return 0;
}
