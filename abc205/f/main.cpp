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

int R, C, N;
int num_vertices;

int cell_id_for_start() {
    return 0;
}

int cell_id_for_r(const int idx) {
    return 1 + idx;
}

int cell_id_for_u(const int idx) {
    return R + 1 + idx;
}

int cell_id_for_v(const int idx) {
    return R + N + 1 + idx;
}

int cell_id_for_c(const int idx) {
    return R + N + N + 1 + idx;
}

int cell_id_for_end() {
    return num_vertices - 1;
}

int main(void) {
    cin >> R >> C >> N;

    num_vertices = R + C + N * 2 + 2;

    mf_graph<int> g(num_vertices);

    for (int r = 0; r < R; r++) {
        g.add_edge(cell_id_for_start(), cell_id_for_r(r), 1);
    }
    for (int i = 0; i < N; i++) {
        g.add_edge(cell_id_for_u(i), cell_id_for_v(i), 1);
    }
    for (int c = 0; c < C; c++) {
        g.add_edge(cell_id_for_c(c), cell_id_for_end(), 1);
    }

    for (int i = 0; i < N; i++) {
        // r = [a, c], c = [b, d]
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;

        for (int r = a; r <= c; r++) {
            g.add_edge(cell_id_for_r(r), cell_id_for_u(i), 1);
        }
        for (int c = b; c <= d; c++) {
            g.add_edge(cell_id_for_v(i), cell_id_for_c(c), 1);
        }
    }

    cout << g.flow(cell_id_for_start(), cell_id_for_end()) << endl;

    return 0;
}
