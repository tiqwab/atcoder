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

const int MAX_N = 500;

// trains[i][j] means the number of trains which starts from i (=L) to j (=R)
vector<vector<int>> trains;

vector<vector<int>> acc;

// ref. YouTube AtCoder ABC 106
void build_acc(const int N) {
    acc.resize(N + 1, vector<int>(N + 1, 0));
    for (int l = 1; l <= N; l++) {
        for (int r = 1; r <= N; r++) {
            acc[l][r] = acc[l][r - 1] + acc[l - 1][r] - acc[l - 1][r - 1] + trains[l][r];
        }
    }

    // acc.resize(N + 1, vector<int>(N + 1, 0));
    // for (int l = 1; l <= N; l++) {
    //     for (int r = l; r <= N; r++) {
    //         acc[l][r] = acc[l][r - 1] + trains[l][r];
    //     }
    // }
    // for (int l = 1; l <= N; l++) {
    //     for (int r = 1; r <= N; r++) {
    //         acc[l][r] += acc[l - 1][r];
    //     }
    // }
}

int main(void) {
    int N, M, Q;
    cin >> N >> M >> Q;

    trains.resize(N + 1, vector<int>(N + 1, 0));
    for (int i = 0; i < M; i++) {
        int L, R;
        cin >> L >> R;
        trains[L][R]++;
    }

    build_acc(N);

    // for (int l = 0; l <= N; l++) {
    //     for (int r = 0; r <= N; r++) {
    //         cout << acc[l][r] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < Q; i++) {
        int p, q;
        cin >> p >> q;
        // printf("[%d, %d]\n", p, q);
        p--;

        cout << acc[q][q] - acc[p][q] - acc[q][p] + acc[p][p] << endl;
    }

    return 0;
}
