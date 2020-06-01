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
    int N;
    cin >> N;

    vector<ll> as(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }
    sort(as.begin(), as.end());

    ll acc = 1;
    bool ok = true;
    for (auto a : as) {
        if (__builtin_mul_overflow(acc, a, &acc)) {
            ok = false;
            break;
        }
        if (acc > 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL) {
            ok = false;
            break;
        }
    }

    if (ok) {
        cout << acc << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
