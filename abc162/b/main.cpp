#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

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
    int N;
    cin >> N;

    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        if (i % 3 != 0 && i % 5 != 0) {
            ans += i;
        }
    }

    cout << ans << endl;

    return 0;
}
