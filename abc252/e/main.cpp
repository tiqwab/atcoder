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

const ll MAX_DIST = LONG_LONG_MAX / 2;

int main(void) {
    int N, M;
    cin >> N >> M;

    // edge_to_id[{from, to}] = road id
    map<pair<int, int>, int> edge_to_id;
    // edges[from] = {to, cost}
    vector<vector<pair<int, ll>>> edges(N);

    for (int i = 0; i < M; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--;
        b--;
        edge_to_id[make_pair(a, b)] = i + 1;
        edge_to_id[make_pair(b, a)] = i + 1;
        edges[a].push_back(make_pair(b, c));
        edges[b].push_back(make_pair(a, c));
    }

    vector<ll> dist(N, MAX_DIST);
    dist[0] = 0;

    vector<int> chosen(N);

    auto f = [](const pair<int, ll>& one, const pair<int, ll>& other) {
        if (one.second != other.second) {
            return one.second > other.second;
        } else {
            return one.first > other.first;
        }
    };
    priority_queue<pair<int, ll>, vector<pair<int, ll>>, decltype(f)> q(f);
    q.push(make_pair(0, 0));

    while (!q.empty()) {
        const pair<int, ll> item = q.top();
        const int from = item.first;
        const ll cur_cost = item.second;
        q.pop();

        if (dist[from] < cur_cost) {
            continue;
        }

        for (auto edge : edges[from]) {
            const int to = edge.first;
            const ll edge_cost = edge.second;
            const ll cost = cur_cost + edge_cost;
            if (cost < dist[to]) {
                dist[to] = cost;
                chosen[to] = edge_to_id[make_pair(from, to)];
                q.push(make_pair(to, cost));
            }
        }
    }

#ifdef DEBUG
    for (int i = 0; i < N; i++) {
        printf("%d: %lld\n", i, dist[i]);
    }
#endif

    for (int i = 1; i < (int) chosen.size(); i++) {
        printf("%d ", chosen[i]);
    }
    printf("\n");

    return 0;
}
