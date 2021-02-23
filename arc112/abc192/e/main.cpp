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

// edges[from] contains vector of {to, cost=T, time=K}
vector<vector<tuple<int, ll, ll>>> edges;

auto eval_f = [](const pair<ll, int>& one, const pair<ll, int>& other) {
    if (one.first != other.first) {
        return one.first > other.first;
    } else {
        return one.second > other.second;
    }
};

vector<ll> dists;

ll dijkstra(const int start, const int goal) {
    // {acc_cost, town}
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, decltype(eval_f)> q(eval_f);

    dists[start] = 0;
    q.push(make_pair(0, start));

    while (!q.empty()) {
        const ll cur_cost = q.top().first;
        const int cur_town = q.top().second;
        q.pop();

        if (dists[cur_town] < cur_cost) {
            continue;
        }

        for (auto &edge : edges[cur_town]) {
            ll cost, time;
            int to;
            tie(to, cost, time) = edge;
            ll start_time = (cur_cost + time - 1) / time * time; // ceil
            if (dists[to] == -1 || start_time + cost < dists[to]) {
                dists[to] = start_time + cost;
                q.push(make_pair(start_time + cost, to));
            }
        }
    }

    return dists[goal];
}

int main(void) {
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    X--;
    Y--;

    edges.resize(N);

    for (int i = 0; i < M; i++) {
        int A, B;
        ll T, K;
        cin >> A >> B >> T >> K;
        A--;
        B--;
        edges[A].push_back(make_tuple(B, T, K));
        edges[B].push_back(make_tuple(A, T, K));
    }

    dists.resize(N, -1);

    ll ans = dijkstra(X, Y);
    cout << ans << endl;

    return 0;
}
