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
    vector<int> as(3);
    for (int i = 0; i < 3; i++) {
        cin >> as[i];
    }
    sort(as.begin(), as.end());

    int ans = 0;
    ans += as[2] - as[1];
    ans += as[1] - as[0];

    cout << ans << endl;

    return 0;
}
