// #include <algorithm>
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
vector<int> deps;

int main(void) {
    int N, M;
    cin >> N >> M;

    edges.resize(N, vector<int>());
    deps.resize(N, 0);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        deps[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < N; i++) {
        if (deps[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;

    while (!q.empty()) {
        auto cur = q.top();
        q.pop();

        ans.push_back(cur);

        for (auto next : edges[cur]) {
            deps[next]--;
            if (deps[next] == 0) {
                q.push(next);
            }
        }
    }

    if ((int) ans.size() != N) {
        printf("%d\n", -1);
        return 0;
    }

    printf("%d", ans[0] + 1);
    for (int i = 1; i < N; i++) {
        printf(" %d", ans[i] + 1);
    }
    printf("\n");
    return 0;
}
