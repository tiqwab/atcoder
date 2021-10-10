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

/*
 * ref. [Union-Find](https://www.slideshare.net/chokudai/union-find-49066733)
 * ref. [AtCoder ABC 157 - AtCoder Live](https://www.youtube.com/watch?v=TdR816rqc3s)
 */
class UnionFind {
    public:
        UnionFind(int n = 0): d(n, -1) {}

        // 0-index, [0, n) in other words
        // Time complexity: O(a(n)) (a = inverse Achkermann function)
        int find(int x) {
            if (d[x] < 0) return x;
            return d[x] = find(d[x]);
        }

        // Return false if x and y are alreday in the same group, otherwise return true.
        // 0-index, [0, n) in other words
        // Time complexity: O(a(n)) (a = inverse Achkermann function)
        bool unite(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) return false;
            if (d[x] > d[y]) swap(x, y);
            d[x] += d[y];
            d[y] = x;
            return true;
        }

        // 0-index, [0, n) in other words
        // Time complexity: O(a(n)) (a = inverse Achkermann function)
        bool same(int x, int y) {
            return find(x) == find(y);
        }

        // 0-index, [0, n) in other words
        // Time complexity: O(1)
        int size(int x) {
            return -d[find(x)];
        }

    private:
        vector<int> d;
};

const int X = 4;
const int Y = 4;

const vector<int> dir_y = {-1, 0, 1, 0};
const vector<int> dir_x = {0, 1, 0, -1};

// 1 if there is a town at (y, x)
vector<vector<int>> board(Y + 2, vector<int>(X + 2, 0));

int solve() {
    int ans = 0;

    for (int bits = 0; bits < (1 << (X * Y)); bits++) {
        // 1 if (y, x) is inside wall
        vector<vector<bool>> area(Y + 2, vector<bool>(X + 2, false));
        for (int i = 0; i < X * Y; i++) {
            if (bits & (1 << i)) {
                const int y = (i / X) + 1;
                const int x = (i % X) + 1;
                area[y][x] = true;
            }
        }

        // check all towns are inside wall
        {
            bool ok = true;
            for (int y = 1; y <= 4; y++) {
                for (int x = 1; x <= 4; x++) {
                    if (board[y][x] == 1 && !area[y][x]) {
                        ok = false;
                        break;
                    }
                }
            }
            if (!ok) {
                continue;
            }
        }

        UnionFind uf((X + 2) * (Y + 2));

        for (int y = 0; y < Y + 2; y++) {
            for (int x = 0; x < X + 2; x++) {
                const int cur_id = y * (X + 2) + x;
                for (int dir = 0; dir < 4; dir++) {
                    const int ny = y + dir_y[dir];
                    const int nx = x + dir_x[dir];
                    if (ny < 0 || ny >= Y + 2 || nx < 0 || nx >= X + 2) {
                        continue;
                    }
                    const int next_id = ny * (X + 2) + nx;
                    if (area[y][x] == area[ny][nx]) {
                        uf.unite(cur_id, next_id);
                    }
                }
            }
        }

        set<int> area_num;
        for (int i = 0; i < (X + 2) * (Y + 2); i++) {
            area_num.insert(uf.find(i));
        }
        if (((int) area_num.size()) == 2) {
            ans++;
        }
    }

    return ans;
}

int main(void) {
    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            int c;
            cin >> c;
            if (c == 1) {
                board[y + 1][x + 1] = 1;
            }
        }
    }

    cout << solve() << endl;

    return 0;
}
