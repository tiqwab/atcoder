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

const vector<pair<int, int>> dirs = {make_pair(-1, 0), make_pair(0, 1), make_pair(1, 0), make_pair(0, -1)};

int H, W;
int sh, sw;
int gh, gw;

vector<vector<char>> board;
vector<vector<int>> edges;
map<char, vector<pair<int, int>>> chars_to_hw;
map<char, bool> chars_used;

vector<vector<int>> dist;

// h is [1, H]
// w is [1, W]
// id is [0, H * W)
int hw_to_id(const pair<int, int> hw) {
    int h = hw.first;
    int w = hw.second;
    return (h - 1) * W + (w - 1);
}
pair<int, int> id_to_hw(const int id) {
    return make_pair((id / W) + 1, (id % W) + 1);
}

void bfs() {
    queue<pair<int, int>> q;
    dist[sh][sw] = 0;
    q.push(make_pair(sh, sw));

    while (!q.empty()) {
        auto elem = q.front();
        q.pop();
        const int cur_h = elem.first;
        const int cur_w = elem.second;
        const int cur_id = hw_to_id(make_pair(cur_h, cur_w));

        for (auto &edge : edges[cur_id]) {
            const int next_id = edge;
            const int next_h = id_to_hw(next_id).first;
            const int next_w = id_to_hw(next_id).second;

            if (dist[next_h][next_w] == -1) {
                dist[next_h][next_w] = dist[cur_h][cur_w] + 1;
                q.push(make_pair(next_h, next_w));
            }
        }

        char c = board[cur_h][cur_w];
        if ('a' <= c && c <= 'z') {
            if (!chars_used[c]) {
                for (auto hw : chars_to_hw[c]) {
                    const int next_h = hw.first;
                    const int next_w = hw.second;
                    if (dist[next_h][next_w] == -1 || dist[cur_h][cur_w] + 1 < dist[next_h][next_w]) {
                        dist[next_h][next_w] = dist[cur_h][cur_w] + 1;
                        q.push(make_pair(next_h, next_w));
                    }
                }

                chars_used[c] = true;
            }
        }
    }
}

int main(void) {
    cin >> H >> W;

    board.resize(H + 2, vector<char>(W + 2, '#'));
    for (int h = 1; h <= H; h++) {
        for (int w = 1; w <= W; w++) {
            char c;
            cin >> c;
            board[h][w] = c;
            if (c == 'S') {
                sh = h;
                sw = w;
            } else if (c == 'G') {
                gh = h;
                gw = w;
            } else if (c >= 'a' && c <= 'z') {
                chars_to_hw[c].push_back(make_pair(h, w));
            }
        }
    }

    edges.resize(H * W, vector<int>());
    for (int h = 1; h <= H; h++) {
        for (int w = 1; w <= W; w++) {
            char c = board[h][w];
            if (c == '#') {
                continue;
            }

            const int id = hw_to_id(make_pair(h, w));

            for (auto dir : dirs) {
                const int nh = h + dir.first;
                const int nw = w + dir.second;
                const int nid = hw_to_id(make_pair(nh, nw));
                if (board[nh][nw] != '#') {
                    edges[id].push_back(nid);
                }
            }
        }
    }

    dist.resize(H + 1, vector<int>(W + 1, -1));
    bfs();

    cout << dist[gh][gw] << endl;

    return 0;
}
