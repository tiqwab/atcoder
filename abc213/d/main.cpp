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

void dfs(const int cur, const int prev, vector<int> &acc) {
    acc.push_back(cur);
    for (auto next : edges[cur]) {
        if (next == prev) {
            continue;
        }
        dfs(next, cur, acc);
        acc.push_back(cur);
    }
}

int main(void) {
    int N;
    cin >> N;

    edges.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i = 0; i < N; i++) {
        sort(edges[i].begin(), edges[i].end());
    }

    vector<int> ans;
    dfs(0, -1, ans);

    printf("%d", ans[0] + 1);
    for (int i = 1; i < (int) ans.size(); i++) {
        printf(" %d", ans[i] + 1);
    }
    printf("\n");

    return 0;
}
