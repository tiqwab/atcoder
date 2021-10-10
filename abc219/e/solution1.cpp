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

const int X = 4;
const int Y = 4;

// {y, x} for each town
vector<pair<int, int>> towns;

int ans = 0;

void connected_dfs(const int cur_v, set<int> &visited, const set<int> &cells) {
    // up
    if (cur_v / 4 > 0) {
        const int next_v = cur_v - 4;
        if (visited.find(next_v) == visited.end() && cells.find(next_v) != cells.end()) {
            visited.insert(next_v);
            connected_dfs(next_v, visited, cells);
        }
    }

    // right
    if (cur_v % 4 < 3) {
        const int next_v = cur_v + 1;
        if (visited.find(next_v) == visited.end() && cells.find(next_v) != cells.end()) {
            visited.insert(next_v);
            connected_dfs(next_v, visited, cells);
        }
    }

    // down
    if (cur_v / 4 < 3) {
        const int next_v = cur_v + 4;
        if (visited.find(next_v) == visited.end() && cells.find(next_v) != cells.end()) {
            visited.insert(next_v);
            connected_dfs(next_v, visited, cells);
        }
    }

    // left
    if (cur_v % 4 > 0) {
        const int next_v = cur_v - 1;
        if (visited.find(next_v) == visited.end() && cells.find(next_v) != cells.end()) {
            visited.insert(next_v);
            connected_dfs(next_v, visited, cells);
        }
    }
}

bool connected(const vector<int> &cells) {
    set<int> vertices;
    for (int i = 0; i < (int) cells.size(); i++) {
        if (cells[i] == 1) {
            vertices.insert(i);
        }
    }

    if (vertices.empty()) {
        return false;
    }

    set<int> visited;
    {
        const int start_v = *vertices.begin(); 
        visited.insert(start_v);
        connected_dfs(start_v, visited, vertices);
    }

#ifdef DEBUG
    printf("visited: ");
    for (auto x : visited) {
        printf("%d ", x);
    }
    printf("\n");
#endif

    return vertices == visited;
}

bool check_format(const vector<int> &cells) {
    // 空きが 1
    for (int y = 1; y < 3; y++) {
        for (int x = 1; x < 3; x++) {
            const int id = y * 4 + x;
            if (cells[id] == 0 &&
                    cells[id - 4] == 1 &&
                    cells[id + 1] == 1 &&
                    cells[id + 4] == 1 &&
                    cells[id - 1] == 1) {
                return false;
            }
        }
    }

    // 空きが 2
    if (cells[1] == 1 && cells[2] == 1 &&
            cells[4] == 1 && cells[5] == 0 && cells[6] == 0 && cells[7] == 1 &&
            cells[9] == 1 && cells[10] == 1) {
        return false;
    }
    if (cells[2] == 1 &&
            cells[5] == 1 && cells[6] == 0 && cells[7] == 1 &&
            cells[9] == 1 && cells[10] == 0 && cells[11] == 1 &&
            cells[14] == 1) {
        return false;
    }
    if (cells[5] == 1 && cells[6] == 1 &&
            cells[8] == 1 && cells[9] == 0 && cells[10] == 0 && cells[11] == 1 &&
            cells[13] == 1 && cells[14] == 1) {
        return false;
    }
    if (cells[1] == 1 &&
            cells[4] == 1 && cells[5] == 0 && cells[6] == 1 &&
            cells[8] == 1 && cells[9] == 0 && cells[10] == 1 &&
            cells[13] == 1) {
        return false;
    }

    // 空きが 3
    if (cells[1] == 1 && cells[2] == 1 &&
            cells[4] == 1 && cells[5] == 0 && cells[6] == 0 && cells[7] == 1 &&
            cells[8] == 1 && cells[9] == 0 && cells[10] == 1 &&
            cells[13] == 1) {
        return false;
    }
    if (cells[1] == 1 && cells[2] == 1 &&
            cells[4] == 1 && cells[5] == 0 && cells[6] == 0 && cells[7] == 1 &&
            cells[9] == 1 && cells[10] == 0 && cells[11] == 1 &&
            cells[14] == 1) {
        return false;
    }
    if (cells[2] == 1 &&
            cells[5] == 1 && cells[6] == 0 && cells[7] == 1 &&
            cells[8] == 1 && cells[9] == 0 && cells[10] == 0 && cells[11] == 1 &&
            cells[13] == 1 && cells[14] == 1) {
        return false;
    }
    if (cells[1] == 1 &&
            cells[4] == 1 && cells[5] == 0 && cells[6] == 1 &&
            cells[8] == 1 && cells[9] == 0 && cells[10] == 0 && cells[11] == 1 &&
            cells[13] == 1 && cells[14] == 1) {
        return false;
    }

    // 空きが 4
    if (cells[1] == 1 && cells[2] == 1 &&
            cells[4] == 1 && cells[5] == 0 && cells[6] == 0 && cells[7] == 1 &&
            cells[8] == 1 && cells[9] == 0 && cells[10] == 0 && cells[11] == 1 &&
            cells[13] == 1 && cells[14] == 1) {
        return false;
    }

    return true;
}

void check(const vector<int> &cells) {
#ifdef DEBUG
    printf("cells: ");
    for (auto cell : cells) {
        printf("%d ", cell);
    }
    printf("\n");
#endif

    if (!connected(cells)) {
        return;
    }

#ifdef DEBUG
    printf("connected.\n");
#endif

    if (!check_format(cells)) {
        return;
    }

#ifdef DEBUG
    printf("good format.\n");
#endif

    bool ok = true;
    for (auto town : towns) {
        const int town_id = town.first * 4 + town.second;
        if (cells[town_id] != 1) {
            ok = false;
            break;
        }
    }
    if (ok) {
        ans++;
#ifdef DEBUG
        printf("ok.\n");
#endif
    }
}

void solve(vector<int> &acc) {
    if (acc.size() == X * Y) {
        check(acc);
        return;
    }

    acc.push_back(0);
    solve(acc);
    acc.pop_back();
    acc.push_back(1);
    solve(acc);
    acc.pop_back();
}

int main(void) {
    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            int c;
            cin >> c;
            if (c == 1) {
                towns.push_back(make_pair(y, x));
            }
        }
    }

    {
        vector<int> cells;
        solve(cells);
    }

    cout << ans << endl;

    return 0;
}
