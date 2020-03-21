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

int main(void) {
    ll N, A, B, C, D, E;
    cin >> N >> A >> B >> C >> D >> E;

    vector<ll> dists(5);
    dists[0] = A;
    dists[1] = B;
    dists[2] = C;
    dists[3] = D;
    dists[4] = E;

    vector<ll> divs(5);
    ll max_div = 0;
    for (int i = 0; i < 5; i++) {
        divs[i] = (N + dists[i] - 1) / dists[i];
        if (max_div < divs[i]) {
            max_div = divs[i];
        }
    }

    cout << 4LL + max_div << endl;

    return 0;
}
