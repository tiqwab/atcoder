#include <algorithm>
#include <iostream>
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

vector<ll> A;

int main(void) {
    int N;
    cin >> N;

    int zero_count = 0;
    int minus_count = 0;
    ll small_abs_value = INF;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        ll x;
        cin >> x;
        A[i] = x;
        if (x == 0) {
            zero_count++;
        } else if (x < 0) {
            minus_count++;
        }
        chmin(small_abs_value, abs(x));
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += abs(A[i]);
    }

    if (zero_count > 0 || (minus_count % 2 == 0)) {
        cout << ans << endl;
    } else {
        ans -= small_abs_value * 2;
        cout << ans << endl;
    }

    return 0;
}
