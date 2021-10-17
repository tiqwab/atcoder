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

// counts[i][j] is the number of children of node i under edge (i -> j)
vector<map<int, int>> counts;

vector<ll> ans;

// calculate counts
int dfs1(const int cur, const int prev, const int N) {
    int ans = 1; // myself

    for (auto next : edges[cur]) {
        if (next == prev) {
            continue;
        }
        const int n = dfs1(next, cur, N);
        ans += n;
        counts[cur][next] = n;
        counts[next][cur] = N - n;
    }

    return ans;
}

// calculates sum of distances from node 0
ll dfs2(const int cur, const int prev, const ll dist, const int N) {
    ll ans = dist;

    for (auto next: edges[cur]) {
        if (next == prev) {
            continue;
        }
        ans += dfs2(next, cur, dist + 1, N);
    }

    return ans;
}

// calculate ans
void dfs3(const int cur, const int prev, const int N) {
    for (auto next : edges[cur]) {
        if (next == prev) {
            continue;
        }

        const ll n = counts[cur][next] - 1; // exclude next
        const ll m = counts[next][cur] - 1; // exlude cur
        ans[next] = ans[cur] - n + m;

        dfs3(next, cur, N);
    }
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

    counts.resize(N);
    ans.resize(N);

    dfs1(0, -1, N);

#ifdef DEBUG
    printf("counts: \n");
    for (int i = 0; i < N; i++) {
        for (auto p : counts[i]) {
            printf("  %d->%d: %d\n", i, p.first, p.second);
        }
    }
#endif

    ans[0] = dfs2(0, -1, 0, N);
    dfs3(0, -1, N);

    for (int i = 0; i < N; i++) {
        printf("%lld\n", ans[i]);
    }

    return 0;
}
