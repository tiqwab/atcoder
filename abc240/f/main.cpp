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

ll solve(const vector<int> &xs, const vector<int> &ys, const int N) {
    ll acc1 = 0;
    ll acc2 = 0;
    ll ans = xs[0];

    for (int i = 0; i < N; i++) {
        const ll x = xs[i];
        const ll y = ys[i];

#ifdef DEBUG
        printf("x: %lld, y: %lld, acc1: %lld, acc2: %lld, ans: %lld\n", x, y, acc1, acc2, ans);
#endif

        const ll next_acc1 = acc1 + acc2 * y + x * y * (y + 1) / 2;
        const ll next_acc2 = acc2 + x * y;
        chmax(ans, next_acc1);

        {
            ll left = 0, right = y + 1;
            while (right - left > 1) {
                ll mid = left + (right - left) / 2;
                if (acc2 + x * mid >= 0) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            if (left > 0) {
                chmax(ans, acc1 + acc2 * left + x * left * (left + 1) / 2);
            }
        }

        acc1 = next_acc1;
        acc2 = next_acc2;
    }

    return ans;
}

int main(void) {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N, M;
        cin >> N >> M;

        vector<int> xs;
        vector<int> ys;
        for (int i = 0; i < N; i++) {
            int x, y;
            cin >> x >> y;
            xs.push_back(x);
            ys.push_back(y);
        }
        printf("%lld\n", solve(xs, ys, N));
    }
    
    return 0;
}
