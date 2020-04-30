#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <cmath>

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
    int N;
    int T, A;
    cin >> N >> T >> A;

    vector<int> hs(N, 0.0);
    for (int i = 0; i < N; i++) {
        cin >> hs[i];
    }

    int cand = INT_MAX;
    int idx = -1;
    for (int i = 0; i < N; i++) {
        double v = abs((1000 * T - hs[i] * 6) - 1000 * A);
        if (v < cand) {
            idx = i;
            cand = v;
        }
    }
    cout << idx + 1 << endl;

    return 0;
}
