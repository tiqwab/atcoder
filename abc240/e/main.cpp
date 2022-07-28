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

// v_range[i] = {L_i, R_i}
vector<pair<int, int>> v_range;

pair<int, int> assign(const int cur_v, int id, vector<int> &visited) {
    visited[cur_v] = true;

    int left = id;
    int right = id;

    for (auto next_v : edges[cur_v]) {
        if (visited[next_v]) {
            continue;
        }
        auto res = assign(next_v, id, visited);
        chmin(left, res.first);
        chmax(right, res.second);
        id = res.second + 1;
    }

    v_range[cur_v] = make_pair(left, right);
    return v_range[cur_v];
}

int main(void) {
    int N;
    cin >> N;

    edges.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    v_range.resize(N);

    {
        vector<int> visited(N, false);
        assign(0, 1, visited);
    }

    for (int i = 0; i < N; i++) {
        printf("%d %d\n", v_range[i].first, v_range[i].second);
    }

    return 0;
}
