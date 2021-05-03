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

int R;
int C;

vector<vector<int>> as;
vector<vector<int>> bs;

// {to, cost}
vector<vector<pair<int, int>>> edges;

int to_id(const int r, const int c) {
    return r * C + c;
}

// {r, c}
pair<int, int> from_id(const int id) {
    int r = id / C;
    int c = id % C;
    return make_pair(r, c);
}

int dijkstra() {
    auto f = [](const pair<int, int>& one, const pair<int, int>& other) {
        if (one.second != other.second) {
            return one.second > other.second;
        } else {
            return one.first > other.first;
        }
    };
    // {id, cost}
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(f)> q(f);

    vector<int> dist(2 * R * C, INF);

    dist[0] = 0;
    q.push(make_pair(0, 0));

    while (!q.empty()) {
        auto elem = q.top();
        q.pop();
        const int cur_id = elem.first;
        const int cur_cost = elem.second;
        if (dist[cur_id] < cur_cost) {
            continue;
        }

        for (auto edge : edges[cur_id]) {
            const int to_id = edge.first;
            const int to_cost = edge.second;
            if (cur_cost + to_cost < dist[to_id]) {
                dist[to_id] = cur_cost + to_cost;
                q.push(make_pair(to_id, dist[to_id]));
            }
        }
    }

    return dist[R * C - 1];
}

int main(void) {
    cin >> R >> C;

    as.resize(R, vector<int>(C, INF));
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C - 1; c++) {
            int a;
            cin >> a;
            as[r][c] = a;
        }
    }

    bs.resize(R, vector<int>(C, INF));
    for (int r = 0; r < R - 1; r++) {
        for (int c = 0; c < C; c++) {
            int b;
            cin >> b;
            bs[r][c] = b;
        }
    }

    edges.resize(2 * R * C);

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            const int from = to_id(r, c);
            if (c < C - 1) {
                // right
                const int to = to_id(r, c + 1);
                const int cost = as[r][c];
                edges[from].push_back(make_pair(to, cost));
            }
            if (c > 0) {
                // left
                const int to = to_id(r, c - 1);
                const int cost = as[r][c - 1];
                edges[from].push_back(make_pair(to, cost));
            }
            if (r < R - 1) {
                // down
                const int to = to_id(r + 1, c);
                const int cost = bs[r][c];
                edges[from].push_back(make_pair(to, cost));
            }

            edges[from].push_back(make_pair(from + R * C, 1));
            edges[from + R * C].push_back(make_pair(from, 0));
            if (r > 0) {
                // up
                const int to = to_id(r - 1, c);
                edges[from + R * C].push_back(make_pair(to + R * C, 1));
            }
        }
    }

    cout << dijkstra() << endl;

    return 0;
}
