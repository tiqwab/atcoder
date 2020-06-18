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

bool ns[201];

int main(void) {
    int X, N;
    cin >> X >> N;

    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        ns[p] = true;
    }

    int ans = -1;

    for (int i = 0; i <= 200; i++) {
        if (X - i >= 0 && !ns[X - i]) {
            ans = X - i;
            break;
        } else if (X + i <= 200 && !ns[X + i]) {
            ans = X + i;
            break;
        }
    }

    assert(ans >= 0 && ans <= 200);
    cout << ans << endl;

    return 0;
}
