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

const int MAX_N = 1000000;
const int INF = INT_MAX / 2;

vector<vector<int>> edges;

int main(void) {
    int A, N;
    cin >> A >> N;

    edges.resize(MAX_N, vector<int>());

    // edge type 1
    for (int i = 1; i < MAX_N; i++) {
        // if (ll(i) * ll(A) < ll(MAX_N)) {
        if (i < (MAX_N + A - 1) / A) {
#ifdef DEBUG
            printf("%d -> %d\n", i, i * A);
#endif
            edges[i].push_back(i * A);
        }
    }

    // edge type 2
    for (int i = 10; i < MAX_N; i++) {
        if (i % 10 == 0) {
            continue;
        }
        const int len = to_string(i).size();
        int x = i % 10;
        for (int j = 0; j < len - 1; j++) {
            x *= 10;
        }
        x = x + i / 10;
#ifdef DEBUG
        // printf("%d -> %d\n", i, x);
#endif
        edges[i].push_back(x);
    }

    vector<int> dist(MAX_N, INF);
    dist[1] = 0;

    // cur_number
    queue<int> que;
    que.push(1);

    while (que.size() > 0) {
        auto cur = que.front();
        que.pop();
        for (auto next : edges[cur]) {
            if (dist[next] == INF) {
                dist[next] = dist[cur] + 1;
                que.push(next);
            }
        }
    }

    if (dist[N] != INF) {
        printf("%d\n", dist[N]);
    } else {
        printf("%d\n", -1);
    }

    return 0;
}
