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
    cin >> N;

    // event[x] is how many people login or logout at day x
    map<int, int> event;

    for (int i = 0 ; i < N; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        event[a]++;
        event[a + b]--;
    }

    vector<int> ans(N + 1, 0);
    int acc = 0;
    int prev_day = 0;
    int prev_cnt = 0;
    for (auto p : event) {
        const int cur_day = p.first;
        const int diff = p.second;
        acc += diff;
#ifdef DEBUG
        printf("ans[%d] += %d - %d\n", prev_cnt, cur_day, prev_day);
#endif
        ans[prev_cnt] += cur_day - prev_day;
        prev_day = cur_day;
        prev_cnt = acc;
    }

    printf("%d", ans[1]);
    for (int i = 2; i <= N; i++) {
        printf(" %d", ans[i]);
    }
    printf("\n");

    return 0;
}
