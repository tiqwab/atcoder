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

// from -> {to, cost}
vector<vector<ll>> edges;

vector<vector<ll>> dists;

void warshall_floyd(const int N) {
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                chmin(dists[i][j], dists[i][k] + dists[k][j]);
            }
        }
    }
}

int main(void) {
    int N, M;
    cin >> N >> M;

    dists.resize(N, vector<ll>(N, INF));
    for (int i = 0; i < N; i++) {
        dists[i][i] = 0;
    }

    edges.resize(N, vector<ll>(N, INF));
    for (int i = 0; i < M; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges[a][b] = c;
        edges[b][a] = c;
        dists[a][b] = c;
        dists[b][a] = c;
    }

    warshall_floyd(N);

#ifdef DEBUG
    printf("dists: \n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%lld ", dists[i][j]);
        }
        printf("\n");
    }
#endif

    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }
            for (int k = 0; k < N; k++) {
                if (i == k || j == k) {
                    continue;
                }
                if (edges[i][j] == INF) {
                    continue;
                }
                if (edges[i][j] >= dists[i][k] + dists[k][j]) {
#ifdef DEBUG
                    printf("dists[%d][%d] >= dists[%d][%d] + dists[%d][%d]\n", i, j, i, k, k, j);
#endif
                    ans++;
                    break;
                }
            }
        }
    }

    cout << ans / 2 << endl;
    return 0;
}
