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

int main(void) {
    int H, W;
    cin >> H >> W;

    const int N = H * W;

    vector<int> as(N);
    int min_v = INF;
    for (int i = 0; i < N; i++) {
        cin >> as[i];
        chmin(min_v, as[i]);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += as[i] - min_v;
    }

    cout << ans << endl;

    return 0;
}
