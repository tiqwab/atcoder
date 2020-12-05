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

// {other, dist}
vector<vector<pair<int, int>>> edges;

vector<int> dist;

int id_of_a(const int floor) {
    return floor;
}

int id_of_b(const int floor) {
    return floor + 100;
}

int dijkstra(const int start, const int goal) {
    auto f = [](const pair<int, int>& one, const pair<int, int>& other) {
        if (one.second != other.second) {
            return one.second > other.second;
        } else {
            return one.first > other.first;
        }
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(f)> q(f);
    dist[start] = 0;
    q.push(make_pair(start, 0));

    while (!q.empty()) {
        auto elem = q.top();
        q.pop();
        const int cur_id = elem.first;
        const int cur_dist = elem.second;
        if (cur_dist > dist[cur_id]) {
            continue;
        }

        for (auto &edge : edges[cur_id]) {
            const int next_id = edge.first;
            const int next_dist = cur_dist + edge.second;
            if (next_dist < dist[next_id]) {
                dist[next_id] = next_dist;
                q.push(make_pair(next_id, next_dist));
            }
        }
    }

    return dist[goal];
}

int main(void) {
    int a, b, x, y;
    cin >> a >> b >> x >> y;

    edges.resize(100 * 2 + 5);

    // for A
    for (int i = 1; i < 100; i++) {
        edges[id_of_a(i)].push_back(make_pair(id_of_a(i + 1), y));
        edges[id_of_a(i + 1)].push_back(make_pair(id_of_a(i), y));
    }

    // for B
    for (int i = 1; i < 100; i++) {
        edges[id_of_b(i)].push_back(make_pair(id_of_b(i + 1), y));
        edges[id_of_b(i + 1)].push_back(make_pair(id_of_b(i), y));
    }

    // for edge between A and B
    for (int i = 2; i <= 100; i++) {
        edges[id_of_a(i)].push_back(make_pair(id_of_b(i - 1), x));
        edges[id_of_b(i - 1)].push_back(make_pair(id_of_a(i), x));
    }
    for (int i = 1; i <= 100; i++) {
        edges[id_of_a(i)].push_back(make_pair(id_of_b(i), x));
        edges[id_of_b(i)].push_back(make_pair(id_of_a(i), x));
    }

    dist.resize(100 * 2 + 5, INF);

    int ans = dijkstra(id_of_a(a), id_of_b(b));
    cout << ans << endl;

    return 0;
}
