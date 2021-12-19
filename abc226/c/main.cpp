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

vector<ll> costs;

// edges[i][j] means i needs j
vector<vector<int>> edges;

void dfs(const int cur, set<int> &required) {
    required.insert(cur);

    for (auto next : edges[cur]) {
        if (required.find(next) == required.end()) {
            dfs(next, required);
        }
    }
}

int main(void) {
    int N;
    cin >> N;

    costs.resize(N);
    edges.resize(N);

    for (int i = 0; i < N; i++) {
        ll T;
        int K;
        cin >> T >> K;
        costs[i] = T;
        for (int j = 0; j < K; j++) {
            int a;
            cin >> a;
            a--;
            edges[i].push_back(a);
        }
    }

    set<int> required;
    dfs(N - 1, required);

    ll ans = 0;
    for (auto r : required) {
        ans += costs[r];
    }

    cout << ans << endl;

    return 0;
}
