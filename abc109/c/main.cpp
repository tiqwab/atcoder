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

int gcd(int x, int y) {
    if (x < y) {
        swap(x, y);
    }
    if (y == 0) {
        return x;
    }
    return gcd(y, x % y);
}

vector<int> xs;

int main(void) {
    int N, X;
    cin >> N >> X;

    xs.resize(N);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        xs[i] = abs(x - X);
    }

    int ans = xs[0];
    for (int i = 1; i < N; i++) {
        ans = gcd(xs[i], ans);
    }

    cout << ans << endl;

    return 0;
}
