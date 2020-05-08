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
    int N;
    cin >> N;

    int ans = 0;
    int min_diff = INF;

    vector<int> vs = {111, 222, 333, 444, 555, 666, 777, 888, 999};
    for (auto v : vs) {
        if (v - N >= 0 && v - N < min_diff) {
            ans = v;
            min_diff = v - N;
        }
    }

    cout << ans << endl;

    return 0;
}
