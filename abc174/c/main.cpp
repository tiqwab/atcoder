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
    int K;
    cin >> K;

    if (K % 2 == 0 || K % 5 == 0) {
        cout << -1 << endl;
        return 0;
    }

    ll x = 7;
    int cnt = 1;
    while (1) {
        if (x % K == 0) {
            break;
        }
        x = (((x * 10) % K) + 7) % K;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
