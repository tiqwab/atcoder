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

ll slen = 3LL * 10000000000LL;

int main(void) {
    int N;
    cin >> N;
    string T;
    cin >> T;
    ll tlen = (ll) T.size();

    if (T == "0") {
        cout << 1 * 10000000000LL << endl;
        return 0;
    } else if (T == "1" ){
        cout << 2 * 10000000000LL << endl;
        return 0;
    }

    string _S = "";
    for (int i = 0; i < 200000; i++) {
        _S += "110";
    }

    int idx = -1;
    for (int i = 0; i < 3; i++) {
        bool ok = true;
        for (int j = 0; j < tlen; j++) {
            if (T[j] != _S[i + j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        cout << 0 << endl;
        return 0;
    }

    // cout << slen / 3 - (idx + tlen) / 3 << endl;
    cout << ((slen - tlen + 1 - idx) + (3 - 1)) / 3 << endl;
    return 0;
}
