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

// {y, x}
vector<pair<ll, ll>> figures;

int main(void) {
    int N;
    cin >> N;

    figures.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> figures[i].second >> figures[i].first;
    }

    sort(figures.begin(), figures.end(), [&](const pair<ll, ll> &a, const pair<ll, ll> &b) {
            // sort by slope (large to small)
            const ll a_y = a.first;
            const ll a_x = a.second;
            const ll b_y = b.first;
            const ll b_x = b.second;
            return b_x * (a_y - 1) > (b_y - 1) * a_x;
    });

    // for (auto p : figures) {
    //     printf("(%lld, %lld)\n", p.first, p.second);
    // }

    int ans = 0;
    pair<ll, ll> prev = make_pair(1, 0);
    for (auto fig : figures) {
        const ll cur_y = fig.first;
        const ll cur_x = fig.second;
        const ll prev_y = prev.first;
        const ll prev_x = prev.second;

        if ((prev_y - 1) * (cur_x - 1) >= cur_y * prev_x) {
            ans += 1;
            prev = fig;
        }
    }

    cout << ans << endl;

    return 0;
}
