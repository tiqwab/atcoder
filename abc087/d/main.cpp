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

// graphs[i] means {to, dist} from vertex i
vector<vector<pair<int, int>>> graph;

vector<int> pos;

void bfs(const int start) {
    queue<int> que;
    pos[start] = 0;
    que.push(start);

    while (!que.empty()) {
        const int cur = que.front();
        que.pop();
        assert(pos[cur] != INF);

        for (auto next : graph[cur]) {
            const int next_v = next.first;
            const int next_d = pos[cur] + next.second;
            if (pos[next_v] == INF) {
                pos[next_v] = next_d;
                que.push(next_v);
            }
        }
    }
}

int main(void) {
    int N, M;
    cin >> N >> M;

    graph.resize(N);
    for (int i = 0; i < M; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        l--;
        r--;
        graph[l].push_back(make_pair(r, d));
        graph[r].push_back(make_pair(l, -1 * d));
    }

    pos.resize(N, INF);

    for (int i = 0; i < N; i++) {
        if (pos[i] == INF) {
            bfs(i);
        }
    }

    for (int i = 0; i < N; i++) {
        assert(pos[i] != INF);
    }

    bool ok = true;
    for (int l = 0; l < N; l++) {
        for (auto &edge : graph[l]) {
            const int r = edge.first;
            const int d = edge.second;
            if (pos[r] - pos[l] != d) {
                ok = false;
            }
        }
    }

    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
