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

// right down
const int DIR_RD = 0;
// right up
const int DIR_RU = 1;

// {RD, RU, LU, LD}
const vector<int> dir_y = {-1, 1, 1, -1};
const vector<int> dir_x = {1, 1, -1, -1};

int cell_to_id(const int y, const int x, const int dir, const int N) {
    if (dir == DIR_RD) {
        return 1 + y * N + x;
    } else {
        return 1 + y * N + x + N * N;
    }
}

// {y, x}
// pair<int, int> id_to_cell(int id, const int N) {
//     if (id == 0) {
//         // start
//         return make_pair(-1, -1);
//     }
//     if (id <= N * N) {
//         id -= 1;
//         const int y = id / N;
//         const int x = id % N;
//         return make_pair(y, x);
//     } else {
//         id -= 1 + N * N;
//         const int y = id / N;
//         const int x = id % N;
//         return make_pair(y, x);
//     }
// }

int main(void) {
    int N;
    cin >> N;
    int sy, sx;
    cin >> sy >> sx;
    sy--;
    sx--;
    int gy, gx;
    cin >> gy >> gx;
    gy--;
    gx--;

    vector<string> board(N);

    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    // {from, {to, cost}}
    vector<vector<pair<int, int>>> edges(N * N * 2 + 10);

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (board[y][x] == '#') {
                continue;
            }

            const int id_rd = cell_to_id(y, x, DIR_RD, N);
            const int id_ru = cell_to_id(y, x, DIR_RU, N);
            edges[id_rd].push_back(make_pair(id_ru, 1));
            edges[id_ru].push_back(make_pair(id_rd, 1));
            for (int i = 0; i < 4; i++) {
                const int ny = y + dir_y[i];
                const int nx = x + dir_x[i];
                if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
                    continue;
                }
                if (board[ny][nx] == '#') {
                    continue;
                }

                if (i == 0 || i == 2) {
                    // RD or LU
                    const int nid = cell_to_id(ny, nx, DIR_RD, N);
                    edges[id_rd].push_back(make_pair(nid, 0));
                } else {
                    // RU or LD
                    const int nid = cell_to_id(ny, nx, DIR_RU, N);
                    edges[id_ru].push_back(make_pair(nid, 0));
                }
            }
        }
    }

    // for start
    {
        const int id_start_rd = cell_to_id(sy, sx, DIR_RD, N);
        const int id_start_ru = cell_to_id(sy, sx, DIR_RU, N);
        edges[0].push_back(make_pair(id_start_rd, 1));
        edges[0].push_back(make_pair(id_start_ru, 1));
    }


    vector<int> dist(N * N * 2 + 10, INF);
    dist[0] = 0;

    // {id, cost}
    deque<pair<int, int>> deq;
    deq.push_back(make_pair(0, 0));

    while (!deq.empty()) {
        auto cur = deq.front();
        deq.pop_front();
        const int cur_id = cur.first;
        const int cur_cost = cur.second;
        if (dist[cur_id] < cur_cost) {
            continue;
        }

        for (auto edge : edges[cur_id]) {
            const int to = edge.first;
            const int cost = edge.second;
            if (dist[to] > cur_cost + cost) {
                dist[to] = cur_cost + cost;
                if (cost == 0) {
                    deq.push_front(make_pair(to, cur_cost + cost));
                } else {
                    deq.push_back(make_pair(to, cur_cost + cost));
                }
            }
        }
    }

    int ans = min(dist[cell_to_id(gy, gx, DIR_RD, N)], dist[cell_to_id(gy, gx, DIR_RU, N)]);
    if (ans == INF) {
        ans = -1;
    }
    cout << ans << endl;

    return 0;
}
