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

const int MAX_T = 200000;

vector<ll> xs(MAX_T + 1, 0);

int main(void) {
    int N;
    ll W;
    cin >> N >> W;

    for (int i = 0; i < N; i++) {
        int s, t;
        ll p;
        cin >> s >> t >> p;
        xs[s] += p;
        xs[t] -= p;
    }

    bool ok = true;
    ll cur = 0;
    for (int i = 0; i <= MAX_T; i++) {
        cur += xs[i];
        if (cur > W) {
            ok = false;
            break;
        }
    }

    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
