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

vector<int> hs;

int main(void) {
    int N, K;
    cin >> N >> K;

    hs.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> hs[i];
    }
    sort(hs.begin(), hs.end());

    int ans = INF;
    for (int i = 0; i <= N - K; i++) {
        chmin(ans, hs[i + K - 1] - hs[i]);
    }

    cout << ans << endl;

    return 0;
}
