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

const int MAX_BITS = 60;

// to[i][j] is the destination of 2^i paths from j
vector<vector<int>> to;

// solution by doubling
int main(void) {
    int N;
    ll K;
    cin >> N >> K;

    to.resize(MAX_BITS, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        t--;
        to[0][i] = t;
    }

    for (int i = 1; i < MAX_BITS; i++) {
        for (int j = 0; j < N; j++) {
            to[i][j] = to[i - 1][to[i - 1][j]];
        }
    }

    int cur = 0;
    for (int i = 0; i < MAX_BITS; i++) {
        int bit = (K >> i) & 1;
        if (bit) {
            cur = to[i][cur];
        }
    }

    cout << cur + 1 << endl;

    return 0;
}
