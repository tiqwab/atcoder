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

vector<int> as;

int main(void) {
    int N, D, X;
    cin >> N >> D >> X;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    int ans = X;
    for (int i = 0; i < N; i++) {
        ans += 1 + (D - 1) / as[i];
    }

    cout << ans << endl;

    return 0;
}
