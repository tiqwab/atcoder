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

ll ans = 0;

void check(const vector<int> &xs, const ll N) {
    vector<int> acc;

    if (xs[0] == 0) {
        return;
    }

    for (int i = 0; i < 2; i++) {
        for (auto x : xs) {
            acc.push_back(x);
        }
    }

    ll cand = 0;
    for (auto x : acc) {
        cand = cand * 10 + x;
    }

    if (cand <= N) {
        ans++;
    }
}

void solve(vector<int> &xs, const int lim, const ll N) {
    const int len = (int) xs.size();
    if (len == lim) {
        check(xs, N);
        return;
    }

    for (int i = 0; i <= 9; i++) {
        xs.push_back(i);
        solve(xs, lim, N);
        xs.pop_back();
    }
}

int main(void) {
    ll N;
    cin >> N;

    for (int lim = 1; lim <= 6; lim++) {
        vector<int> xs;
        solve(xs, lim, N);
    }

    cout << ans << endl;

    return 0;
}
