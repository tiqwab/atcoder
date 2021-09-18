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

const ll MAX_A = 2 * 1000 * 1000 * 1000;

bool check(const ll border, const vector<ll> &as, const int N, const ll K) {
    ll cnt = 0;
    for (auto a : as) {
        if (a >= border) {
            cnt += a - border + 1;
        }
    }
    return cnt > K;
}

int main(void) {
    int N, K;
    cin >> N >> K;

    vector<ll> as(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    ll left = 0;
    ll right = MAX_A + 10;
    while (right - left > 1) {
        ll mid = left + (right - left) / 2;
        if (check(mid, as, N, K)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    ll ans = 0;
    ll border = right;
    int cnt = 0;
    for (auto a : as) {
        if (a >= border) {
            int c = a - border + 1;
            ans += c * (border + a) / 2;
            cnt += c;
        }
    }
    ans += (K - cnt) * (border - 1);
    cout << ans << endl;
}
