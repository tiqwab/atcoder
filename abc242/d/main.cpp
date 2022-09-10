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

char solve(const string &S, const ll t, const ll k) {
    ll pos = k - 1;
    int diff = 0;
    ll i = 0;
    for (; i < t && pos != 0; i++) {
        if (pos % 2 == 0) {
            diff = (diff + 1) % 3;
        } else {
            diff = (diff + 2) % 3;
        }
        pos = pos / 2;
    }

    if (i < t) {
        diff = (diff + ((t - i) % 3)) % 3;
    }

    return 'A' + ((S[pos] - 'A' + diff) % 3);
}

int main(void) {
    string S;
    cin >> S;
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        ll t, k;
        cin >> t >> k;
        printf("%c\n", solve(S, t, k));
    }
    return 0;
}
