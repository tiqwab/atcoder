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

vector<int> as;

int main(void) {
    int N;
    cin >> N;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    ll ans = 0;
    int cur_h = as[0];
    for (int i = 1; i < N; i++) {
        if (cur_h > as[i]) {
            // printf("i: %d, += %d\n", i, cur_h - as[i]);
            ans += cur_h - as[i];
        } else {
            cur_h = as[i];
        }
    }

    cout << ans << endl;

    return 0;
}
