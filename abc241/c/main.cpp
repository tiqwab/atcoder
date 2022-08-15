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

const vector<int> dir_y = {-1, 0, 1, 1};
const vector<int> dir_x = {1, 1, 1, 0};

vector<vector<char>> board;

bool check(const int start_y, const int start_x, const int dy, const int dx, const int N) {
    int count = 0;
    for (int i = 0; i < 6; i++) {
        const int y = start_y + dy * i;
        const int x = start_x + dx * i;
        if (y < 0 || y >= N || x < 0 || x >= N) {
            return false;
        }
        if (board[y][x] == '.') {
            count++;
        }
    }
    return count <= 2;
}

int main(void) {
    int N;
    cin >> N;

    board.resize(N, vector<char>(N, '.'));
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            board[i][j] = s[j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 4; k++) {
                if (check(i, j, dir_y[k], dir_x[k], N)) {
#ifdef DEBUG
                    printf("%d, %d, %d, %d\n", i, j, dir_y[k], dir_x[k]);
#endif
                    printf("Yes\n");
                    return 0;
                }
            }
        }
    }

    printf("No\n");
    return 0;
}
