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

vector<vector<int>> edges;
map<int, int> dists;

void solve(const int start, const int N) {
    vector<int> dist(N, INF);
    dist[start] = 0;

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto next : edges[cur]) {
            if (dist[next] != INF) {
                continue;
            }

            dist[next] = dist[cur] + 1;
            q.push(next);
        }
    }

    for (int i = 0; i < N; i++) {
        dists[dist[i]]++;
    }
}

int main(void) {
    int N, X, Y;
    cin >> N >> X >> Y;

    edges.resize(N);
    for (int i = 0; i < N; i++) {
        if (i != N - 1) {
            edges[i].push_back(i + 1);
        }
        if (i != 0) {
            edges[i].push_back(i - 1);
        }
    }
    edges[X - 1].push_back(Y - 1);
    edges[Y - 1].push_back(X - 1);

    for (int i = 0; i < N; i++) {
        solve(i, N);
    }

    for (int i = 1; i < N; i++) {
        cout << dists[i] / 2 << endl;
    }

    return 0;
}
