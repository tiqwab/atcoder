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

vector<ll> A;

int main(void) {
    ll K, N;
    cin >> K >> N;

    A.resize(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    A[N] = K + A[0];

    ll ans = K;
    for (int i = 1; i <= N; i++) {
        chmin(ans, K - (A[i] - A[i - 1]));
    }
    cout << ans << endl;

    return 0;
}
