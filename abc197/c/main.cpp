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

vector<int> as;

int dfs(const int cur_pos, const int bits, const int acc, const int N) {
    if (cur_pos == N) {
        return acc;
    }

    int cand = INF;

    if (bits & (1 << cur_pos)) {
        chmin(cand, dfs(cur_pos + 1, bits, acc | as[cur_pos], N));
    } else {
        chmin(cand, acc ^ dfs(cur_pos + 1, bits, as[cur_pos], N));
    }

    return cand;
}

int main(void) {
    int N;
    cin >> N;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    int ans = INF;

    for (int bits = 0; bits < (1 << N); bits++) {
        int acc = as[0];
        chmin(ans, dfs(1, bits, acc, N));
    }

    cout << ans << endl;

    return 0;
}
