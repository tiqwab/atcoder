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

vector<int> dy = {-1, 0, 1, 0};
vector<int> dx = {0, 1, 0, -1};

// (1, 1) is board[2][2]
vector<vector<char>> board;

int solve(const pair<int, int> start, const pair<int, int> goal, const int H, const int W) {
    // {dist, position}
    typedef pair<int, pair<int, int>> Elem;

    priority_queue<Elem, vector<Elem>, greater<Elem>> q;
    vector<vector<int>> dist(H + 4, vector<int>(W + 4, INF));

    dist[start.first][start.second] = 0;
    q.push(make_pair(0, start));

    while (!q.empty()) {
        auto elem = q.top();
        q.pop();
        const int cur_dist = elem.first;
        const pair<int, int> cur_pos = elem.second;
        if (dist[cur_pos.first][cur_pos.second] < cur_dist) {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            const pair<int, int> next_pos = make_pair(cur_pos.first + dy[i], cur_pos.second + dx[i]);
            int next_dist = cur_dist;
            if (board[next_pos.first][next_pos.second] == '#') {
                continue;
            }
            if (chmin(dist[next_pos.first][next_pos.second], next_dist)) {
                dist[next_pos.first][next_pos.second] = next_dist;
                q.push(make_pair(next_dist, next_pos));
            }
        }

        for (int i = -2; i <= 2; i++) {
            for (int j = -2; j <= 2;j ++) {
                const pair<int, int> next_pos = make_pair(cur_pos.first + i, cur_pos.second + j);
                int next_dist = cur_dist + 1;
                if (board[next_pos.first][next_pos.second] == '#') {
                    continue;
                }
                if (chmin(dist[next_pos.first][next_pos.second], next_dist)) {
                    dist[next_pos.first][next_pos.second] = next_dist;
                    q.push(make_pair(next_dist, next_pos));
                }
            }
        }
    }

    return dist[goal.first][goal.second];
}

int main(void) {
    int H, W;
    cin >> H >> W;

    pair<int, int> start, goal;
    {
        int ch, cw, dh, dw;
        cin >> ch >> cw >> dh >> dw;
        ch += 1;
        cw += 1;
        dh += 1;
        dw += 1;
        start = make_pair(ch, cw);
        goal = make_pair(dh, dw);
    }

    board.resize(H + 4, vector<char>(W + 4, '#'));
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            char s;
            cin >> s;
            board[h + 2][w + 2] = s;
        }
    }

#ifdef DEBUG
    printf("board: \n");
    for (auto line : board) {
        for (auto cell : line) {
            cout << cell << " ";
        }
        cout << endl;
    }
#endif

    int ans = solve(start, goal, H, W);
    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
