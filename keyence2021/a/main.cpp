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

vector<ll> as;
vector<ll> bs;
vector<ll> cs;

int main(void) {
    int N;
    cin >> N;

    as.resize(N, 0);
    bs.resize(N, 0);
    cs.resize(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> bs[i];
    }

    cs[0] = as[0] * bs[0];
    ll max_a = as[0];
    for (int i = 1; i < N; i++) {
        cs[i] = cs[i - 1];
        chmax(max_a, as[i]);
        chmax(cs[i], max_a * bs[i]);
    }

    for (int i = 0; i < N; i++) {
        printf("%lld\n", cs[i]);
    }

    return 0;
}
