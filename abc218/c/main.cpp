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

// block if 1, empty if 0
vector<vector<int>> S;
vector<vector<int>> T;

vector<vector<int>> rotate(const vector<vector<int>> &board, const int N) {
    vector<vector<int>> new_board(N, vector<int>(N));
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            int new_y = x;
            int new_x = N - 1 - y;
            new_board[new_y][new_x] = board[y][x];
        }
    }

    return new_board;
}

pair<int, int> calc_offset(const vector<vector<int>> &board, const int N) {
    int offset_y = N;
    int offset_x = N;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (board[y][x] == 1) {
                chmin(offset_y, y);
                chmin(offset_x, x);
            }
        }
    }

    // should not come here
    return make_pair(offset_y, offset_x);
}

vector<vector<int>> normalize(const vector<vector<int>> &board, const pair<int, int> offset, const int N) {
    vector<vector<int>> res(N, vector<int>(N, 0));
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (board[y][x] == 1) {
                res[y - offset.first][x - offset.second] = 1;
            }
        }
    }
    return res;
}

int main(void) {
    int N;
    cin >> N;

    S.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            if (c == '#') {
                S[i][j] = 1;
            } else {
                S[i][j] = 0;
            }
        }
    }

    T.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            if (c == '#') {
                T[i][j] = 1;
            } else {
                T[i][j] = 0;
            }
        }
    }

    pair<int, int> offset_for_t = calc_offset(T, N);
    vector<vector<int>> normalized_t = normalize(T, offset_for_t, N);

    for (int i = 0; i < 4; i++) {
        if (i != 0) {
            S = rotate(S, N);
        }

#ifdef DEBUG
        printf("board:\n");
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                printf("%d ", S[y][x]);
            }
            printf("\n");
        }
#endif

        pair<int, int> offset_for_s = calc_offset(S, N);
        vector<vector<int>> normalized_s = normalize(S, offset_for_s, N);

        if (normalized_s == normalized_t) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
