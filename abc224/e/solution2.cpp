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

// max_for_row[i] contains the max steps for row i
map<int, int> max_for_row;

// max_for_col[i] contains the max steps for row col i
map<int, int> max_for_col;

// pos[cell_id] = {r, c}
map<int, pair<int, int>> pos;

// vs[value] = cell_ids
map<int, vector<int>> vs;

vector<int> ans;

int main(void) {
    int H, W, N;
    cin >> H >> W >> N;

    for (int i = 0; i < N; i++) {
        int r, c, a;
        cin >> r >> c >> a;
        r--;
        c--;
        pos[i] = make_pair(r, c);
        // want to iterate reverse order
        vs[-1 * a].push_back(i);
    }

    ans.resize(N, 0);

    for (auto value_and_cell_ids : vs) {
        vector<int> cell_ids = value_and_cell_ids.second;

        for (auto cell_id : cell_ids) {
            const int row = pos[cell_id].first;
            const int col = pos[cell_id].second;
            if (max_for_row.find(row) != max_for_row.end()) {
                chmax(ans[cell_id], max_for_row[row] + 1);
            }
            if (max_for_col.find(col) != max_for_col.end()) {
                chmax(ans[cell_id], max_for_col[col] + 1);
            }
        }

        for (auto cell_id : cell_ids) {
            const int row = pos[cell_id].first;
            const int col = pos[cell_id].second;
            chmax(max_for_row[row], ans[cell_id]);
            chmax(max_for_col[col], ans[cell_id]);
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}
