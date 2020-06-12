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
    int X;
    cin >> X;

    int ans = 1;
    for (int i = 2; i < 100; i++) {
        int a = i * i;
        while (a * i <= X) {
            a *= i;
        }
        if (a <= X) {
            chmax(ans, a);
        }
    }

    cout << ans << endl;
    return 0;
}
