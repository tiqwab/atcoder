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

const ll MX = 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL;

int main(void) {
    int N;
    cin >> N;

    vector<ll> as(N);
    bool has_zero = false;
    for (int i = 0; i < N; i++) {
        cin >> as[i];
        if (as[i] == 0) {
            has_zero = true;
        }
    }

    if (has_zero) {
        cout << 0 << endl;
        return 0;
    }

    bool ok = true;
    ll acc = 1;
    for (int i = 0; i < N; i++) {
        if (acc > MX / as[i]) {
            ok = false;
            break;
        }
        acc *= as[i];
    }

    if (ok) {
        cout << acc << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
