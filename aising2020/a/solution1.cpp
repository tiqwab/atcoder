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
    int L, R, d;
    cin >> L >> R >> d;

    int ans = 0;
    for (int i = d; i <= R; i += d) {
        if (i >= L && i <= R) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
