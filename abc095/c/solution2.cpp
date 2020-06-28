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

const int INF = INT_MAX / 2;

int main(void) {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int ans = INF;

    // buy only A and B pizza
    chmin(ans, A * X + B * Y);

    // buy only C pizza
    chmin(ans, max(X, Y) * 2 * C);

    // buy A, B, and C pizza
    if (X < Y) {
        int acc = 2 * C * X;
        acc += (Y - X) * B;
        chmin(ans, acc);
    } else {
        int acc = 2 * C * Y;
        acc += (X - Y) * A;
        chmin(ans, acc);
    }

    cout << ans << endl;

    return 0;
}
