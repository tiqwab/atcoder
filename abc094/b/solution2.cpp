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
    int N, M, X;
    cin >> N >> M >> X;

    vector<int> as(M);
    for (int i = 0; i < M; i++) {
        cin >> as[i];
    }

    auto it = lower_bound(as.begin(), as.end(), X);
    int l_cnt = distance(as.begin(), it);
    int r_cnt = distance(it, as.end());

    cout << min(l_cnt, r_cnt) << endl;

    return 0;
}
