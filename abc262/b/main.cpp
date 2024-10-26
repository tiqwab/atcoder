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

int main(void) {
    int N, M;
    cin >> N >> M;

    vector<vector<bool>> edges(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++) {
        edges[i][i] = true;
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges[u][v] = true;
        edges[v][u] = true;
    }

    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                if (edges[i][j] && edges[j][k] && edges[k][i]) {
                    ans += 1;
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
