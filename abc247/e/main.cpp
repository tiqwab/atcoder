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
    int N, X, Y;
    cin >> N >> X >> Y;

    vector<int> as;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        as.push_back(x);
    }
    as.push_back(X + 1); // as sentinel

    ll ans = 0;

    int pos_min = -1;
    int pos_max = -1;
    int prev_border = -1;

    for (int pos = 0; pos < (int) as.size(); pos++) {
        const int x = as[pos];

        if (x == X) {
            // x is same as max
            if (pos_max >= 0 && pos_min >= 0) {
                const int pos_left = min(pos_max, pos_min);
                const int pos_right = max(pos_max, pos_min);
                assert(pos_left - prev_border > 0);
                assert(pos - pos_right > 0);
                ans += ll(pos_left - prev_border) * ll(pos - pos_right);
            }
            pos_max = pos;
        }

        if (x == Y) {
            // x is same as min
            // avoid adding ans when X == Y because it is already calculated in if block 'x == X'
            if (pos_max >= 0 && pos_min >= 0 && X != Y) {
                const int pos_left = min(pos_max, pos_min);
                const int pos_right = max(pos_max, pos_min);
                assert(pos_left - prev_border > 0);
                assert(pos - pos_right > 0);
                ans += ll(pos_left - prev_border) * ll(pos - pos_right);
            }
            pos_min = pos;
        }

        if (x > X || x < Y) {
            // x is larger than max or smaller than min
            if (pos_max >= 0 && pos_min >= 0) {
                const int pos_left = min(pos_max, pos_min);
                const int pos_right = max(pos_max, pos_min);
                assert(pos_left - prev_border > 0);
                assert(pos - pos_right > 0);
                ans += ll(pos_left - prev_border) * ll(pos - pos_right);
            }
            pos_min = -1;
            pos_max = -1;
            prev_border = pos;
        }
    }

    cout << ans << endl;

    return 0;
}
