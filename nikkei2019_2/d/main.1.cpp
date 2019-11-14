#include <algorithm>
#include <iostream>

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

#define min(a, b) (a < b) ? a : b

class Edge {
    public:
        int l;
        int r;
        int c;
};

const int MAX_N = 100000;
const int MAX_M = 100000;

int n;
int m;
Edge edges[MAX_M];
ll dp[MAX_N];

void print_edges() {
    for (int i = 0; i < m; i++) {
        printf("edges[%d]: {l=%d, r=%d, c=%d}\n", i, edges[i].l, edges[i].r, edges[i].c);
    }
}

int main(void) {
    cin >> n;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        edges[i].l = l;
        edges[i].r = r;
        edges[i].c = c;
    }

    for (int x = 1; x < n; x++) {
        dp[x] = LONG_LONG_MAX / 2;
    }

    auto f = [](const Edge &a, const Edge &b) {
        if (a.l < b.l) {
            return true;
        } else if (a.l > b.l) {
            return false;
        } else {
            return a.r < b.r;
        }
    };

    sort(&edges[0], &edges[m - 1], f);

    if (edges[0].l == 1) {
        for (int x = edges[0].l; x < edges[0].r; x++) {
            dp[x] = edges[0].c;
        }
    }

    for (int y = 1; y < m; y++) {
        for (int x = edges[y].l - 1; x <= edges[y].r - 1; x++) {
            ll m = min(dp[edges[y].l - 1] + edges[y].c, dp[x]);
            chmin(dp[x], m);
        }
    }

    if (dp[n - 1] == LONG_LONG_MAX / 2) {
        cout << -1 << endl;
    } else {
        cout << dp[n - 1] << endl;
    }

    return 0;
}
