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

ll calc(const ll N, const ll M) {
    ll ans = 0;

    // (1) the first line
    {
        // left
        ;
        // middle
        ;
        // right
        ;
    }

    // (2) the middle line
    {
        // left
        ;
        // middle
        if (N >= 3 && M >= 3) {
            ans += (N - 2) * (M - 2);
        }
        // right
        ;
    }

    // (3) the bottom line
    {
        // left
        ;
        // middle
        ;
        // right
        ;
    }

    return ans;
}

int main(void) {
    ll N, M;
    cin >> N >> M;
    // assume that N <= M
    if (N > M) {
        swap(N, M);
    }

    ll ans = 0;

    if (N == 1) {
        if (M == 1) {
            ans = 1;
        } else if (M == 2) {
            ans = 0;
        } else {
            ans = M - 2;
        }
    } else {
        ans = calc(N, M);
    }

    cout << ans << endl;

    return 0;
}
