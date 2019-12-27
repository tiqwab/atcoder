#include <algorithm>
#include <iostream>
#include <queue>
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
const int MAX_N = 100005;

int dist[MAX_N][3];

int main(void) {
    int N, M;
    cin >> N >> M;

    vector<vector<int> > edges(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        edges[u - 1].push_back(v - 1);
    }

    int S, T;
    cin >> S >> T;
    S--;
    T--;

    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < 3; j++) {
            dist[i][j] = INF;
        }
    }

    // {vertex, dist}
    queue<pair<int, int> > q;
    q.push({S, 0});
    dist[S][0] = 0;
    while (!q.empty()) {
        int v = q.front().first;
        int d = q.front().second;
        q.pop();
        for (int i = 0; i < (int) edges[v].size(); i++) {
            int nv = edges[v][i];
            int nd = d + 1;
            int nl = (d + 1) % 3;
            if (dist[nv][nl] != INF) continue;
            dist[nv][nl] = nd;
            q.push({nv, nd});
        }
    }

    int ans;
    if (dist[T][0] == INF) ans = -1;
    else ans = dist[T][0] / 3;
    cout << ans << endl;

    return 0;
}
