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

    vector<bool> as(N + 1, false);
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        as[a] = true;
    }

    int l_cnt = 0;
    for (int i = X - 1; i > 0; i--) {
        if (as[i]) {
            l_cnt++;
        }
    }
    int r_cnt = 0;
    for (int i = X + 1; i < N; i++) {
        if (as[i]) {
            r_cnt++;
        }
    }

    // printf("l_cnt: %d, r_cnt: %d\n", l_cnt, r_cnt);
    cout << min(l_cnt, r_cnt) << endl;

    return 0;
}
