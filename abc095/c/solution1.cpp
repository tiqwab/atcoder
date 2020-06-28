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
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int ans = INF;
    for (int num_c = 0; num_c <= 200000; num_c += 2) {
        int num_a = max(0, X - num_c / 2);
        int num_b = max(0, Y - num_c / 2);
        int cand = num_a * A + num_b * B + C * num_c;
        chmin(ans, cand);
    }

    cout << ans << endl;

    return 0;
}
