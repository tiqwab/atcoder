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

// {day, price}
vector<pair<int, ll>> events;

int main(void) {
    int N;
    ll C;
    cin >> N >> C;

    for (int i = 0; i < N; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        events.push_back(make_pair(a, c));
        events.push_back(make_pair(b + 1, -c));
    }
    sort(events.begin(), events.end());

    ll ans = 0LL;
    ll acc = 0LL;
    ll cur_day = 1;

    int i = 0;
    while (i < (int) events.size()) {
        ans += min(acc, C) * (events[i].first - cur_day);
        cur_day = events[i].first;

        while (events[i].first == cur_day) {
            acc += events[i].second;
            i++;
        }
    }

    cout << ans << endl;

    return 0;
}
