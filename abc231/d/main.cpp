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

vector<vector<int>> edges;

bool dfs(const int cur, const int prev, vector<bool> &visited) {
    visited[cur] = true;
    for (auto next : edges[cur]) {
        if (next == prev) {
            continue;
        }
        if (visited[next]) {
            return false;
        }
        if (!dfs(next, cur, visited)) {
            return false;
        }
    }
    return true;
}

int main(void) {
    int N, M;
    cin >> N >> M;

    edges.resize(N);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    for (int i = 0; i < N; i++) {
        if (edges[i].size() >= 3) {
            printf("No\n");
            return 0;
        }
    }

    vector<bool> visited(N, false);
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            if (!dfs(i, -1, visited)) {
                printf("No\n");
                return 0;
            }
        }
    }

    printf("Yes\n");
    return 0;
}
