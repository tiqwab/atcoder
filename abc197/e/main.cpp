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

const ll INF = LONG_LONG_MAX / 2;

// {number, pos}
map<int, set<int>> balls;

// {l, r} order by number
vector<pair<int, int>> areas;

int main(void) {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, c;
        cin >> x >> c;
        c--;
        balls[c].insert(x);
    }

    for (int i = 0; i < N; i++) {
        if (balls.find(i) != balls.end()) {
            int left_ball_pos = *(balls[i].begin());
            int right_ball_pos = *(balls[i].rbegin());
#ifdef DEBUG
            printf("number: %d, left: %d, right: %d\n", i, left_ball_pos, right_ball_pos);
#endif
            areas.push_back(make_pair(left_ball_pos, right_ball_pos));
        }
    }

    areas.push_back(make_pair(0, 0));

    // {pos, sum_dist}
    map<ll, ll> acc;
    acc[0] = 0;
    for (auto area : areas) {
        const ll next_left = area.first;
        const ll next_right = area.second;

        ll left_sum_dist = INF;
        ll right_sum_dist = INF;

        for (auto p : acc) {
            const ll cur_pos = p.first;
            const ll cur_sum_dist = p.second;

            chmin(left_sum_dist, next_right - next_left + cur_sum_dist + abs(cur_pos - next_right));
            chmin(right_sum_dist, next_right - next_left + cur_sum_dist + abs(cur_pos - next_left));
        }

        map<ll, ll> tmp;
        tmp[next_left] = left_sum_dist;
        tmp[next_right] = right_sum_dist;
        swap(acc, tmp);
    }

    ll ans = INF;
    for (auto p : acc) {
        chmin(ans, p.second);
    }
    cout << ans << endl;

    return 0;
}
