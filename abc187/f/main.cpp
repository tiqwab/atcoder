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

vector<int> edges;

vector<int> dp;

int main(void) {
    int N, M;
    cin >> N >> M;

    edges.resize(N, 0);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        edges[a] |= 1 << b;
        edges[b] |= 1 << a;
    }

    dp.resize(1 << N, INF);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        dp[1 << i] = 1;
    }

    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            if ((i & (1 << j)) == 0) {
                continue;
            }
            if (dp[i] != INF) {
                continue;
            }

            int x = i ^ (1 << j);
            if (dp[x] == 1 && (edges[j] & x) == x) {
                dp[i] = 1;
            }
        }
    }

    for (int i = 0; i < (1 << N); i++) {
        for (int j = i; j > 0; j = (j - 1) & i) {
            int k = i - j;
            chmin(dp[i], dp[j] + dp[k]);
        }
    }

    cout << dp[(1 << N) - 1] << endl;

    return 0;
}
