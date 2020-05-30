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

int N;
vector<ll> as;

vector<ll> ss;

// Return the index of ss where the latter half starts.
// For example, if init_left = 0, init_right = 4, and the returned value is 3,
// the area is separated as [0, 3) and [3, 4)
//
// Note that it is possible that the area should be separated at right - 1.
int binary_search(int init_left, int init_right) {
    ll s = ss[init_right] - ss[init_left];
    int left = init_left, right = init_right, mid;
    while (right - left > 1) {
        mid = left + (right - left) / 2;
        if ((ss[mid] - ss[init_left]) * 2 < s) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return right;
}

ll solve(const int N) {
    ll ans = INF;

    for (int center = 2; center < N - 1; center++) {
        ll mn = INF;
        ll mx = 0;
        {
            // left
            int l = binary_search(0, center);
            vector<int> ls = {l, l - 1};
            pair<ll, ll> res = {0, INF};
            for (auto left : ls) {
                ll s_first = ss[left] - ss[0];
                ll s_second = ss[center] - ss[left];
                // printf("left: %d, center: %d, [0, left): %lld, [left, center): %lld\n",
                //         left, center, s_first, s_second);
                if (abs(s_first - s_second) < abs(res.first - res.second)) {
                    res = {s_first, s_second};
                }
            }
            chmin(mn, res.first);
            chmax(mx, res.first);
            chmin(mn, res.second);
            chmax(mx, res.second);
        }
        {
            // right
            int r = binary_search(center, N);
            vector<int> rs = {r, r - 1};
            pair<ll, ll> res = {0, INF};
            for (auto right : rs) {
                ll s_first = ss[right] - ss[center];
                ll s_second = ss[N] - ss[right];
                // printf("center: %d, right: %d, [center, right): %lld, [right, N): %lld\n",
                //         center, right, s_first, s_second);
                if (abs(s_first - s_second) < abs(res.first - res.second)) {
                    res = {s_first, s_second};
                }
            }
            chmin(mn, res.first);
            chmax(mx, res.first);
            chmin(mn, res.second);
            chmax(mx, res.second);
        }

        chmin(ans, mx - mn);
    }

    return ans;
}

// ref. https://drken1215.hatenablog.com/entry/2018/08/28/193000
int main(void) {
    cin >> N;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    ss.resize(N + 1, 0);
    for (int i = 0; i < N; i++) {
        ss[i + 1] = ss[i] + as[i];
    }

    cout << solve(N) << endl;

    return 0;
}
