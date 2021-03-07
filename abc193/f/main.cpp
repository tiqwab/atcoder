#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>

#include <atcoder/all>
using namespace atcoder;

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

// right, down, left, up
const vector<int> dy = {0, 1, 0, -1};
const vector<int> dx = {1, 0, -1, 0};

int main(void) {
    int N;
    cin >> N;

    const int num_cells = N * N;

    vector<char> cells(num_cells);
    for (int i = 0; i < N * N; i++) {
        char c;
        cin >> c;
        cells[i] = c;
    }

    const int s_id = num_cells;  // black
    const int g_id = num_cells + 1; // white

    mf_graph<int> g(num_cells + 2);
    int tot = 0;

    for (int cur_id = 0; cur_id < num_cells; cur_id++) {
        for (int i = 0; i < 4; i++) {
            const int ny = cur_id / N + dy[i];
            const int nx = cur_id % N + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
                continue;
            }
            const int next_id = ny * N + nx;
            g.add_edge(cur_id, next_id, 1);
            if (cur_id < next_id) {
                tot++;
            }
        }
    }

    // 5 is enough because the maximum benefit of one cell is 4 (the number of neighbors)?
    const int M = 5;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            const int cur_id = y * N + x;

            if (cells[cur_id] == '?') {
                g.add_edge(s_id, cur_id, M);
                g.add_edge(cur_id, g_id, M);
                tot += M;
            } else if ((cells[cur_id] == 'B') ^ ((y + x) % 2 == 0)) {
                g.add_edge(s_id, cur_id, M);
            } else {
                g.add_edge(cur_id, g_id, M);
            }
        }
    }

    int ans = tot - g.flow(s_id, g_id);
    cout << ans << endl;
    
    return 0;
}
