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
    string S;
    cin >> S;

    const int slen = (int) S.size();
    bool ok = true;

    for (int i = 1; i <= slen; i++) {
        const char c = S[i - 1];
        if (i % 2 == 0) {
            if (c >= 'A' && c <= 'Z') {
                // ok
            } else {
                ok = false;
                break;
            }
        } else {
            if (c >= 'A' && c <= 'Z') {
                ok = false;
                break;
            } else {
                // ok
            }
        }
    }

    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
