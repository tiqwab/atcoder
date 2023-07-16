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

int my_lower_bound(const int x, const vector<int> &xs) {
    int l = -1;
    int r = (int) xs.size();
    while (r - l > 1) {
        int mid = l + (r - l) / 2;
        if (xs[mid] < x) {
            l = mid;
        } else {
            r = mid;
        }
    }

    return r;
}

int my_upper_bound(const int x, const vector<int> &xs) {
    int l = -1;
    int r = (int) xs.size();
    while (r - l > 1) {
        int mid = l + (r - l) / 2;
        if (xs[mid] <= x) {
            l = mid;
        } else {
            r = mid;
        }
    }

    return r;
}

int main(void) {
    int N;
    cin >> N;

    vector<vector<int>> positions(N + 1);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        positions[a].push_back(i + 1);
    }

    for (int i = 0; i < N + 1; i++) {
        sort(positions[i].begin(), positions[i].end());
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int l, r, x;
        cin >> l >> r >> x;

        auto pos_l = my_lower_bound(l, positions[x]);
        auto pos_r = my_upper_bound(r, positions[x]);
        printf("%d\n", pos_r - pos_l);

        // auto pos_l = lower_bound(positions[x].begin(), positions[x].end(), l);
        // auto pos_r = upper_bound(positions[x].begin(), positions[x].end(), r);
        // printf("%ld\n", pos_r - pos_l);
    }

    return 0;
}
