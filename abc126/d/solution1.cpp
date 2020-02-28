#include <algorithm>
#include <iostream>
#include <vector>

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

struct Edge {
    int v;
    int w;
};

vector<vector<struct Edge>> edges;
vector<int> colors;

void solve(const int prev, const int cur) {
    const int cur_color = colors[cur];
    for (auto &edge : edges[cur]) {
        // printf("prev: %d, cur: %d, edge.v: %d, edge.w: %d, cur_color: %d\n", prev, cur, edge.v, edge.w, cur_color);
        if (edge.v == prev) {
            continue;
        }
        if (edge.w % 2 == 0) {
            colors[edge.v] = cur_color;
        } else {
            colors[edge.v] = 0x1 ^ cur_color;
        }
        solve(cur, edge.v);
    }
}

int main(void) {
    int N;
    cin >> N;

    edges.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }

    colors.resize(N);
    colors[0] = 0;

    solve(-1, 0);

    for (int i = 0; i < N; i++) {
        cout << colors[i] << endl;
    }


    return 0;
}
