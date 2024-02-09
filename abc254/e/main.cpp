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

void dfs(int cur_pos, int cur_dist, set<int> &acc, const int max_dist, const vector<vector<int>> &edges, const int N) {
    if (cur_dist > max_dist) {
        return;
    }

    acc.insert(cur_pos);

    for (auto next_pos : edges[cur_pos]) {
        dfs(next_pos, cur_dist + 1, acc, max_dist, edges, N);
    }
}

ll solve(const int start, const int max_dist, const vector<vector<int>> &edges, const int N) {
    set<int> acc;

    dfs(start, 0, acc, max_dist, edges, N);

    ll ans = 0;
    for (auto x : acc) {
        ans += x + 1;
    }
    return ans;
}

int main(void) {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> edges(N, vector<int>());

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int x, k;
        cin >> x >> k;
        x--;
        printf("%lld\n", solve(x, k, edges, N));
    }

    return 0;
}
