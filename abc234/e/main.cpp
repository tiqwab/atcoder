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

ll ans = INF;

// assume that X >= 10
void dfs(const ll acc, const int pos, const int cur, const int diff, const ll X, const string &str_X) {
    if (pos == (int) str_X.size()) {
        if (acc >= X) {
            chmin(ans, acc);
        }
        return;
    }

    if (cur >= 0 && cur < 10) {
        dfs(acc * 10 + cur, pos + 1, cur + diff, diff, X, str_X);
    }
}

int main(void) {
    ll X;
    cin >> X;
    string str_X = to_string(X);

    if (X < 10) {
        printf("%lld\n", X);
        return 0;
    }

    for (int i = 1; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            ll acc = i * 10 + j;
            int diff = j - i;
            int cur = j + diff;
            dfs(acc, 2, cur, diff, X, str_X);
        }
    }

    cout << ans << endl;
    return 0;
}
