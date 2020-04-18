#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

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

const int MAX_H = 100;

vector<int> hs;
vector<vector<int>> table;

int solve(const int N) {
    int ans = 0;

    for (int h = 0; h < MAX_H; h++) {
        int pos = 0;
        while (true) {
            while (table[h][pos] == 0 && pos < N) pos++;
            if (pos >= N) break;
            while (table[h][pos] == 1 && pos < N) pos++;
            ans++;
            if (pos >= N) break;
        }
    }

    return ans;
}

int main(void) {
    int N;
    cin >> N;

    hs.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> hs[i];
    }

    table.resize(MAX_H);
    for (int i = 0; i < MAX_H; i++) {
        table[i].resize(N, 0);
        for (int j = 0; j < N; j++) {
            if (hs[j] > i) {
                table[i][j] = 1;
            }
        }
    }

    // for (int i = 0; i < MAX_H; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << table[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << solve(N) << endl;

    return 0;
}
