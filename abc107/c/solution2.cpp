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

vector<int> candles;

ll solve(const int N, const int K) {
    int ans = INF;

    for (int i = 0; i < N - K + 1; i++) {
        int l = candles[i];
        int r = candles[i + K - 1];
        chmin(ans, abs(l) + abs(r - l));
        chmin(ans, abs(r) + abs(r - l));
    }

    return ans;
}

int main(void) {
    int N, K;
    cin >> N >> K;

    candles.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> candles[i];
    }

    cout << solve(N, K) << endl;

    return 0;
}
