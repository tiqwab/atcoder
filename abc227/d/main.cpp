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

vector<ll> as;

bool check(const ll mid, const int N, const ll K) {
    ll acc = 0;

    for (int i = 0; i < N; i++) {
        acc += min(as[i], mid);
    }

    return acc / K >= mid;
}

int main(void) {
    int N, K;
    cin >> N >> K;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        as[i] = a;
    }

    ll left = 0, right = ll(2e17) + 5;

    while (right - left > 1) {
        ll mid = left + (right - left) / 2;
        if (check(mid, N, K)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << left << endl;

    return 0;
}
