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
    int N, K;
    cin >> N >> K;

    vector<int> ps(N);
    for (int i = 0; i < N; i++) {
        cin >> ps[i];
    }
    sort(ps.begin(), ps.end());

    int ans = 0;
    for (int i = 0; i < K; i++) {
        ans += ps[i];
    }

    cout << ans << endl;

    return 0;
}
