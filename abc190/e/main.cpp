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

const int INF = INT_MAX / 2;

vector<vector<int>> edges;
vector<int> cs;

// idx_for_cs[i] is the index of cs which has value i
map<int, int> idx_for_cs;

// dists[i][j] is the distance between C_i and C_j
vector<vector<int>> dists;

// start: one of stones in cs
//
// Return true if there is no route from start to any stone in cs
bool dijkstra_for_cs(const int start, const int N) {
    // distance from start
    vector<int> ds(N, INF);

    // {cur_stone, dist}
    auto f = [](const pair<int, int>& one, const pair<int, int>& other) {
        if (one.second != other.second) {
            return one.second > other.second;
        } else {
            return one.first > other.first;
        }
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(f)> q(f);

    ds[start] = 0;
    q.push(make_pair(start, 0));

    while (!q.empty()) {
        int cur_stone = q.top().first;
        int cur_dist = q.top().second;
        q.pop();

        if (cur_dist > ds[cur_stone]) {
            continue;
        }

        for (auto next_stone : edges[cur_stone]) {
            if (cur_dist + 1 < ds[next_stone]) {
                ds[next_stone] = cur_dist + 1;
                q.push(make_pair(next_stone, ds[next_stone]));
            }
        }
    }

    for (auto c : cs) {
        if (ds[c] == INF) {
            return false;
        }
        chmin(dists[idx_for_cs[start]][idx_for_cs[c]], ds[c]);
    }

    return true;
}

vector<vector<int>> dp;

int solve(const int bits, const int cur, const int K) {
    if (dp[bits][cur] != INF) {
        return dp[bits][cur];
    }

    const int new_bits = bits ^ (1 << cur);
    int cand = INF;

    for (int i = 0 ; i < K; i++) {
        if (new_bits & (1 << i)) {
            chmin(cand, solve(new_bits, i, K) + dists[cur][i]);
        }
    }

    dp[bits][cur] = cand;
    return cand;
}

int main(void) {
    int N, M;
    cin >> N >> M;

    edges.resize(N);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        edges[A].push_back(B);
        edges[B].push_back(A);
    }

    int K;
    cin >> K;

    for (int i = 0; i < K; i++) {
        int C;
        cin >> C;
        C--;
        cs.push_back(C);
        idx_for_cs[C] = i;
    }

    dists.resize(K, vector<int>(K, INF));

    for (auto c : cs) {
        if (!dijkstra_for_cs(c, N)) {
            cout << -1 << endl;
            return 0;
        }
    }

#ifdef DEBUG
    printf("dists: \n");
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            cout << dists[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
#endif

    dp.resize(1 << K, vector<int>(K, INF));
    dp[0][0] = 0;
    for (int i = 0 ; i < K; i++) {
        dp[1 << i][i] = 1;
    }

    int ans = INF;
    for (int i = 0; i < K; i++) {
        chmin(ans, solve((1 << K) - 1, i, K));
    }
    cout << ans << endl;

    return 0;
}
