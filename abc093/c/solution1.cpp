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
    int A, B, C;
    cin >> A >> B >> C;

    const int mx = max({A, B, C});
    const int S = A + B + C;

    int target;
    if (mx % 2 == S % 2) {
        target = mx;
    } else {
        target = mx + 1;
    }

    int acc = (target - A) + (target - B) + (target - C);
    cout << acc / 2 << endl;

    return 0;
}
