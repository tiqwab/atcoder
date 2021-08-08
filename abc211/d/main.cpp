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

const ll MOD = 1000 * 1000 * 1000 + 7;
const int INF = INT_MAX / 2;

vector<vector<int>> edges;

int main(void) {
    int N, M;
    cin >> N >> M;

    edges.resize(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    vector<int> dist(N, INF);
    dist[0] = 0;

    vector<ll> cnt(N, 0);
    cnt[0] = 1;

    // {dist, pos}
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));

    while (!q.empty()) {
        auto elem = q.front();
        const int cur_dist = elem.first;
        const int cur_pos = elem.second;
        q.pop();
        if (dist[cur_pos] < cur_dist) {
            continue;
        }

        for (auto next_pos : edges[cur_pos]) {
            const int next_dist = cur_dist + 1;
            if (next_dist == dist[next_pos]) {
                cnt[next_pos] = (cnt[next_pos] + cnt[cur_pos]) % MOD;
            } else if (next_dist < dist[next_pos]) {
                dist[next_pos] = next_dist;
                cnt[next_pos] = (cnt[next_pos] + cnt[cur_pos]) % MOD;
                q.push(make_pair(next_dist, next_pos));
            }
        }
    }

    cout << cnt[N - 1] << endl;

    return 0;
}
