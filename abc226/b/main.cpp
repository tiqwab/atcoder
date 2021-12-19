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

bool check(const vector<int> &xs, const vector<int> &ys) {
    return xs == ys;
}

int main(void) {
    int N;
    cin >> N;

    vector<vector<int>> lss;

    for (int i = 0; i < N; i++) {
        int L;
        cin >> L;

        vector<int> ls;
        for (int j = 0; j < L; j++) {
            int x;
            cin >> x;
            ls.push_back(x);
        }

        lss.push_back(ls);
    }

    sort(lss.begin(), lss.end());

    int prev_idx = 0;
    int ans = 1;

    for (int i = 1; i < N; i++) {
        auto prev = lss[prev_idx];
        auto cur = lss[i];
        if (!check(prev, cur)) {
            ans += 1;
            prev_idx = i;
        }
    }

    cout << ans << endl;

    return 0;
}
