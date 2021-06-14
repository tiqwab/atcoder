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

int dfs(const int cur, vector<bool> &visited) {
    visited[cur] = true;

    int ans = 1;

    for (auto next : edges[cur]) {
        if (!visited[next]) {
            ans += dfs(next, visited);
        }
    }

    return ans;
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
    }


    int ans = 0;

    for (int i = 0; i < N; i++) {
        vector<bool> visited(N, false);
        ans += dfs(i, visited);
    }

    cout << ans << endl;

    return 0;
}
