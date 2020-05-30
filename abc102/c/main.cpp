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

const ll INF = LONG_LONG_MAX / 2;

int N;
vector<ll> as;
vector<ll> bs;

int main(void) {
    cin >> N;

    ll sum = 0;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
        as[i] -= (i + 1);
        sum += as[i];
    }

    // printf("sum: %lld\n", sum);

    bs = as;
    sort(bs.begin(), bs.end());

    ll b = bs[N / 2];
    // printf("b: %lld\n", b);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += abs(bs[i] - b);
    }
    cout << ans << endl;

    return 0;
}
