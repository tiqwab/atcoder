#include <algorithm>
#include <iostream>
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
    int r, D, x;
    cin >> r >> D >> x;

    ll ans = x;
    for (int i = 1; i <= 10; i++) {
        ans = ans * r - D;
        cout << ans << endl;
    }

    return 0;
}
