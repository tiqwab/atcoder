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

vector<vector<int>> ds;
vector<vector<int>> cs;

map<int, int> gs[3];

int calc(const int c1, const int c2, const int c3, const int N, const int C) {
    int ans = 0;

    vector<int> colors = {c1, c2, c3};

    for (int i = 0; i < 3; i++) {
        int to = colors[i];
        for (auto p : gs[i]) {
            int from = p.first;
            int cnt = p.second;
            // printf("from: %d, to: %d, cnt: %d\n", from, to, cnt);
            ans += ds[from][to] * cnt;
        }
    }

    return ans;
}

int solve(const int N, const int C) {
    int ans = INF;
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < C; j++) {
            for (int k = 0; k < C; k++) {
                if (i == j || i == k || j == k) {
                    continue;
                }
                chmin(ans, calc(i, j, k, N, C));
            }
        }
    }
    return ans;
}

int main(void) {
    int N, C;
    cin >> N >> C;

    ds.resize(C, vector<int>(C));
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < C; j++) {
            cin >> ds[i][j];
        }
    }

    cs.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int c;
            cin >> c;
            c--;
            cs[i][j] = c;
            gs[(i + j) % 3][c]++;
        }
    }

    cout << solve(N, C) << endl;

    return 0;
}
