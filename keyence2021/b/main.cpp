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

const int MAX_N = 300000;

map<int, int> as;

int main(void) {
    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        as[a]++;
    }

    int ans = 0;
    int rem_box = K;
    for (int i = 0; i <= MAX_N; i++) {
        int x = as[i];
        if (rem_box > x) {
            ans += (rem_box - x) * i;
            rem_box = x;
        }
    }

    cout << ans << endl;

    return 0;
}
