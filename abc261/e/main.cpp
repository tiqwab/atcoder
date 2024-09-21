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

int main(void) {
    int N;
    int C;
    cin >> N >> C;

    vector<pair<int, int>> commands;
    for (int i = 0; i < N; i++) {
        int t;
        int a;
        cin >> t >> a;
        commands.push_back(make_pair(t, a));
    }

    vector<vector<vector<int>>> ops(N + 1);
    for (int i = 0 ; i < N + 1; i++) {
        ops[i].resize(32, vector<int>(2, 0));
    }

    for (int j = 0; j < 32; j++) {
        // ops[0][j][0] = (C >> j) & 1;
        // ops[0][j][1] = (C >> j) & 1;
        ops[0][j][1] = 1;
    }

    for (int i = 0; i < N; i++) {
        auto command = commands[i];
        int t = command.first;
        int a = command.second;

        for (int j = 0; j < 32; j++) {
            for (int k = 0; k < 2; k++) {
                if (t == 1) {
                    // and
                    ops[i + 1][j][0] = ops[i][j][0] & ((a >> j) & 1);
                    ops[i + 1][j][1] = ops[i][j][1] & ((a >> j) & 1);
                } else if (t == 2) {
                    // or
                    ops[i + 1][j][0] = ops[i][j][0] | ((a >> j) & 1);
                    ops[i + 1][j][1] = ops[i][j][1] | ((a >> j) & 1);
                } else if (t == 3) {
                    // xor
                    ops[i + 1][j][0] = ops[i][j][0] ^ ((a >> j) & 1);
                    ops[i + 1][j][1] = ops[i][j][1] ^ ((a >> j) & 1);
                }
            }
        }
#ifdef DEBUG
        printf("dp: \n");
        for (int j = 0; j < 32; j++) {
            for (int k = 0; k < 2; k++) {
                printf("%d ", ops[i + 1][j][k]);
            }
            printf("\n");
        }
        printf("\n");
#endif
    }


    int acc = C;

    for (int i = 0; i < N; i++) {
        int tmp = 0;
        for (int j = 0; j < 32; j++) {
            int bit = ops[i + 1][j][(acc >> j) & 1];
            tmp += bit << j;
        }
        acc = tmp;
        printf("%d\n", acc);
    }

    return 0;
}
