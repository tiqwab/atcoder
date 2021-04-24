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
    int A, B;
    cin >> A >> B;

    int ans = 1;

    for (int i = 2; i <= B; i++) {
        int l = ((A + i - 1) / i) * i;
        int r = (B / i) * i;

        if (A <= l && l <= B && A <= r && r <= B && l < r) {
            ans = i;
        }
    }

    cout << ans << endl;

    return 0;
}
