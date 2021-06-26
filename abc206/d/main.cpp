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

const int MAX_A = 200000;

int dfs(const int cur, vector<bool> &visited, const vector<vector<int>> &edges) {
    visited[cur] = true;
    int ans = 1;
    for (auto next : edges[cur]) {
        if (!visited[next]) {
            ans += dfs(next, visited, edges);
        }
    }
    return ans;
}

int main(void) {
    int N;
    cin >> N;

    vector<int> as(N);
    for (int i = 0 ; i < N; i++) {
        cin >> as[i];
        as[i]--;
    }

    // {v, set of vertices having relation to v}
    map<int, set<int>> relations;
    for (int i = 0 ; i < N; i++) {
        int me = as[i];
        int other = as[N - 1 - i];
        if (me != other) {
            relations[me].insert(other);
        }
    }

#ifdef DEBUG
    for (auto p : relations) {
        printf("%d: ", p.first);
        for (auto x : p.second) {
            printf("%d ", x);
        }
        printf("\n");
    }
#endif

    vector<vector<int>> edges(MAX_A);
    for (auto p : relations) {
        int me = p.first;
        for (auto other : p.second) {
            edges[me].push_back(other);
        }
    }

    vector<bool> visited(MAX_A, false);
    int ans = 0;

    for (int i = 0; i < MAX_A; i++) {
        if (relations.find(i) != relations.end()) {
            if (!visited[i]) {
#ifdef DEBUG
                printf("start from %d\n", i);
#endif
                int v_num = dfs(i, visited, edges);
#ifdef DEBUG
                printf("  v_num: %d\n", v_num);
#endif
                ans += v_num - 1;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
