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

map<ll, ll> ms;

int main(void) {
    int N;
    cin >> N;

    ll acc = 0;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        ms[a]++;
        acc += a;
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int b, c;
        cin >> b >> c;
        acc -= b * ms[b];
        acc -= c * ms[c];
        ms[c] += ms[b];
        ms[b] = 0;
        acc += c * ms[c];
        cout << acc << endl;
    }

    return 0;
}
