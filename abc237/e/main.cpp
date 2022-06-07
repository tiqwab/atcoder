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
const ll COST_BASE = 100LL * 1000LL * 1000LL + 1LL;

vector<int> hs;
// {to, cost}
vector<vector<pair<int, ll>>> edges;
vector<ll> dist;

void dijkstra(const int N) {
    // {cur_v, sum_cost}
    auto f = [](const pair<int, ll>& one, const pair<int, ll>& other) {
        if (one.second != other.second) {
            return one.second > other.second;
        } else {
            return one.first > other.first;
        }
    };
    priority_queue<pair<int, ll>, vector<pair<int, ll>>, decltype(f)> q(f);

    dist.resize(N, INF);
    dist[0] = 0;
    q.push(make_pair(0, 0));

    while (!q.empty()) {
        const int cur_v = q.top().first;
        const ll cur_cost = q.top().second;
        q.pop();
        if (dist[cur_v] < cur_cost) {
            continue;
        }

        for (const auto &edge : edges[cur_v]) {
            const int next_v = edge.first;
            const ll next_cost = cur_cost + edge.second;
            if (next_cost < dist[next_v]) {
                dist[next_v] = next_cost;
                q.push(make_pair(next_v, next_cost));
            }
        }
    }

#ifdef DEBUG
    printf("dist: \n");
    for (int i = 0; i < N; i++) {
        printf("  0 -> %d: %lld\n", i, dist[i]);
    }
#endif
}

int main(void) {
    int N, M;
    cin >> N >> M;

    hs.resize(N);
    for (int i = 0 ; i < N; i++) {
        int h;
        cin >> h;
        hs[i] = h;
    }

    edges.resize(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        ll u_to_v_cost = hs[u] - hs[v] >= 0 ? 0 : -1 * (hs[u] - hs[v]);
        ll v_to_u_cost = hs[v] - hs[u] >= 0 ? 0 : -1 * (hs[v] - hs[u]);
        edges[u].push_back(make_pair(v, u_to_v_cost));
        edges[v].push_back(make_pair(u, v_to_u_cost));
    }

    dijkstra(N);

    ll ans = -INF;
    for (int i = 0; i < N; i++) {
        chmax(ans, hs[0] - hs[i] - dist[i]);
    }
    printf("%lld\n", ans);

    return 0;
}
