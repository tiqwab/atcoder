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

vector<vector<int>> board;

bool check(const int lim, const int N, const int K) {
    // acc[i][j] is acc of board[0][0] to board[i - 1][j - 1]
    vector<vector<int>> acc(N + 1, vector<int>(N + 1, 0));

    for (int h = 0; h < N; h++) {
        for (int w = 0; w < N; w++) {
            acc[h + 1][w + 1] = acc[h][w + 1] + acc[h + 1][w] - acc[h][w];
            if (board[h][w] > lim) {
                acc[h + 1][w + 1] += 1;
            }
        }
    }

    for (int h = 1; h + K - 1 <= N; h++) {
        for (int w = 1; w + K - 1 <= N; w++) {
            int cnt = acc[h + K - 1][w + K - 1]
                - acc[h + K - 1][w - 1]
                - acc[h - 1][w + K - 1]
                + acc[h - 1][w - 1];
            if (cnt < K * K / 2 + 1) {
                return true;
            }
        }
    }

    return false;
}

const int MAX_A = 1000 * 1000 * 1000;

int main(void) {
    int N, K;
    cin >> N >> K;

    board.resize(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    int left = -1;
    int right = MAX_A;
    while (right - left > 1) {
        int mid = left + (right - left) / 2;
#ifdef DEBUG
        printf("left = %d, right = %d, mid = %d\n", left, right, mid);
#endif
        if (check(mid, N, K)) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << right << endl;

    return 0;
}
