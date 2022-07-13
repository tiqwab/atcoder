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

const int MAX_N = 20;

vector<int> values;
vector<vector<int>> edges;
vector<vector<int>> children;

vector<int> dfs(const int cur_v, vector<bool> &visited) {
    visited[cur_v] = true;

    vector<int> res;
    res.push_back(values[cur_v]);

    for (auto child_v : edges[cur_v]) {
        if (visited[child_v]) {
            continue;
        }
        vector<int> child_values = dfs(child_v, visited);
        for (auto v : child_values) {
            res.push_back(v);
        }
    }

    sort(res.begin(), res.end());
    reverse(res.begin(), res.end());
    res = vector<int>(res.begin(), res.begin() + min((int) res.size(), MAX_N));
    children[cur_v] = res;

    return res;
}

void pre_calc(const int N) {
    vector<bool> visited(N);
    dfs(0, visited);
}

int main(void) {
    int N, Q;
    cin >> N >> Q;

    values.resize(N);
    edges.resize(N);
    children.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> values[i];
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    pre_calc(N);

#ifdef DEBUG
    printf("children: \n");
    for (int i = 0; i < N; i++) {
        for (auto v : children[i]) {
            printf("%d ", v);
        }
        printf("\n");
    }
#endif

    for (int i = 0; i < Q; i++) {
        int v, k;
        cin >> v >> k;
        v--;
        k--;
        printf("%d\n", children[v][k]);
    }

    return 0;
}
