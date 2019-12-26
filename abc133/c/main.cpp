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

int main(void) {
    ll L, R;
    cin >> L >> R;

    if (R - L >= 2019) {
        cout << 0 << endl;
        return 0;
    }

    ll cand = INF;
    for (int i = L; i <= R; i++) {
        for (int j = i + 1; j <= R; j++) {
            ll x = ((i % 2019) * (j % 2019)) % 2019;
            chmin(cand, x);
        }
    }

    cout << cand << endl;
    
    return 0;
}
