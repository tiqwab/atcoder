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

// 各閉路について塗る順番を決める
void dfs1(const int cur_v, vector<int> &vs, vector<bool> &visited) {
    vs.push_back(cur_v);
    visited[cur_v] = true;
    for (auto next_v : edges[cur_v]) {
        if (visited[next_v]) {
            continue;
        }
        dfs1(next_v, vs, visited);
    }
}

// 各閉路について順番に沿って実際に塗る (全探索)
ll dfs2(const int cur_i, const vector<int> &vs, vector<int> &colors) {
    const int cur_v = vs[cur_i];
    ll ans = 0;

    if (cur_i == (int) vs.size()) {
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        const int cur_color = 1 << i;
        colors[cur_v] = cur_color;

        bool ok = true;
        for (auto next_v : edges[cur_v]) {
            if (colors[next_v] == cur_color) {
                ok = false;
                break;
            }
        }

        if (!ok) {
            continue;
        }

        ans += dfs2(cur_i + 1, vs, colors);
    }

    colors[cur_v] = 0;
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
        edges[b].push_back(a);
    }

    ll ans = 1;
    vector<int> colors(N, 0);
    vector<bool> visited(N, false);

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            vector<int> vs;
            dfs1(i, vs, visited);
            ll x = dfs2(0, vs, colors);
            ans *= x;
        }
    }

    cout << ans << endl;

    return 0;
}
