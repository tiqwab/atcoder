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

vector<pair<int, int>> walls;

int main(void) {
    int N, D;
    cin >> N >> D;

    for (int i = 0; i < N; i++) {
        int l, r;
        cin >> l >> r;
        walls.push_back(make_pair(l, r));
    }
    sort(walls.begin(), walls.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            if (a.second != b.second) {
                return a.second < b.second;
            }
            return a.first < b.first;
    });
#ifdef DEBUG
    printf("walls: \n");
    for (auto w : walls) {
        printf("  (%d, %d)\n", w.first, w.second);
    }
#endif

    int ans = 0;
    int prev_punch_point = -INF;

    for (auto wall : walls) {
        const int cur_l = wall.first;
        const int cur_r = wall.second;
        if (prev_punch_point + D - 1 < cur_l) {
            ans += 1;
            prev_punch_point = cur_r;
#ifdef DEBUG
            printf("punch wall (%d, %d) at %d\n", cur_l, cur_r, prev_punch_point); 
#endif
        }
    }

    printf("%d\n", ans);
    return 0;
}
