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

const ll INF = LONG_LONG_MAX / 2;
const ll MAX_COST = ll(1000) * ll(1000) * ll(1000) * ll(10);

void dfs(int cur, set<int> &visited, const ll border, const vector<vector<ll>> &edges, const int N) {
    visited.insert(cur);

    for (int next = 0; next < N; next++) {
        ll cost = edges[cur][next];
        if (cost <= border) {
            if (visited.find(next) == visited.end()) {
                dfs(next, visited, border, edges, N);
            }
        }
    }
}

bool check(const ll border, const vector<vector<ll>> &edges, const int N) {
    for (int i = 0; i < N; i++) {
        set<int> visited;
        dfs(i, visited, border, edges, N);
        if (((int) visited.size()) == N) {
            return true;
        }
    }
    return false;
}

int main(void) {
    int N;
    cin >> N;

    // (x, y, p)
    vector<tuple<ll, ll, ll>> points;
    for (int i = 0; i < N; i++) {
        ll x, y, p;
        cin >> x >> y >> p;
        points.push_back(make_tuple(x, y, p));
    }

    // edges[i][j]: cost for i -> j
    vector<vector<ll>> edges(N, vector<ll>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                edges[i][j] = INF;
                continue;
            }
            ll x1, y1, p1, x2, y2, p2;
            tie(x1, y1, p1) = points[i];
            tie(x2, y2, p2) = points[j];

            ll cost = (abs(x1 - x2) + abs(y1 - y2) + (p1 - 1)) / p1;
            edges[i][j] = cost;
        }
    }

#ifdef DEBUG
    printf("edges: \n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%lld ", edges[i][j]);
        }
        printf("\n");
    }
    printf("\n");
#endif

    ll l = 0;
    ll r = MAX_COST;

    while (r - l > 1) {
        ll mid = l + (r - l) / 2;
        if (check(mid, edges, N)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    printf("%lld\n", r);

    return 0;
}
