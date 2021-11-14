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

// rows[i] contains set of {value, cell_id} in row i
map<int, set<pair<int, int>>> rows;

// cols[i] contains set of {value, cell_id} in col i
map<int, set<pair<int, int>>> cols;

// pos[cell_id] = {r, c}
map<int, pair<int, int>> pos;

// {value, cell_id}
vector<pair<int, int>> vs;

vector<int> ans;

void calc_for_row(const int row, const int value, const int cell_id) {
    static map<pair<int, int>, int> memo;

    if (memo.find(make_pair(row, value)) != memo.end()) {
        chmax(ans[cell_id], memo[make_pair(row, value)]);
        // printf("use memo. row: %d, value: %d, memo: %d\n", row, value, memo[make_pair(row, value)]);
        return;
    }

    auto it = rows[row].upper_bound(make_pair(value, INF));
    if (it != rows[row].end()) {
        const int upper_value = (*it).first;
        while (it != rows[row].end() && (*it).first == upper_value) {
            const int next_cell_id = (*it).second;
            chmax(ans[cell_id], ans[next_cell_id] + 1);
            it++;
        }
    }

    memo[make_pair(row, value)] = ans[cell_id];
}

void calc_for_cal(const int col, const int value, const int cell_id) {
    static map<pair<int, int>, int> memo;

    if (memo.find(make_pair(col, value)) != memo.end()) {
        chmax(ans[cell_id], memo[make_pair(col, value)]);
        // printf("use memo. col: %d, value: %d, memo: %d\n", col, value, memo[make_pair(col, value)]);
        return;
    }

    auto it = cols[col].upper_bound(make_pair(value, INF));
    if (it != cols[col].end()) {
        const int upper_value = (*it).first;
        while (it != rows[col].end() && (*it).first == upper_value) {
            const int next_cell_id = (*it).second;
            chmax(ans[cell_id], ans[next_cell_id] + 1);
            it++;
        }
    }

    memo[make_pair(col, value)] = ans[cell_id];
}

// This is not an efficient solution.
// It passes only with C++ (Clang 10.0.0) not C++ (GCC 9.2.1)
int main(void) {
    int H, W, N;
    cin >> H >> W >> N;

    for (int i = 0; i < N; i++) {
        int r, c, a;
        cin >> r >> c >> a;
        r--;
        c--;
        rows[r].insert(make_pair(a, i));
        cols[c].insert(make_pair(a, i));
        pos[i] = make_pair(r, c);
        vs.push_back(make_pair(a, i));
    }

#ifdef DEBUG
    printf("rows: \n");
    for (int h = 0; h < H; h++) {
        for (auto x : rows[h]) {
            printf("(%d,%d) ", x.first, x.second);
        }
        printf("\n");
    }

    printf("cols: \n");
    for (int w = 0; w < W; w++) {
        for (auto x : cols[w]) {
            printf("(%d,%d) ", x.first, x.second);
        }
        printf("\n");
    }
#endif

    sort(vs.begin(), vs.end());
    reverse(vs.begin(), vs.end());

    ans.resize(N, 0);

    for (int i = 1; i < N; i++) {
        const int value = vs[i].first;
        const int cell_id = vs[i].second;
        const int row = pos[cell_id].first;
        const int col = pos[cell_id].second;

#ifdef DEBUG
        printf("value: %d, cell_id: %d, row: %d, col: %d\n",
                value, cell_id, row, col);
#endif

        {
            calc_for_row(row, value, cell_id);
        }

        {
            calc_for_cal(col, value, cell_id);
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}
