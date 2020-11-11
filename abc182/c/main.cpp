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

bool f(const int acc, const int cur, const int rem, const string &S, const int slen) {
    if (rem == 0) {
        return acc % 3 == 0;
    }

    if (cur >= slen) {
        return false;
    }

    int d = S[cur] - '0';

    if (f(acc + d, cur + 1, rem - 1, S, slen)) {
        return true;
    }

    if (f(acc, cur + 1, rem, S, slen)) {
        return true;
    }

    return false;
}

int main(void) {
    string S;
    cin >> S;
    int slen = (int) S.size();

    for (int i = slen; i > 0; i--) {
        if (f(0, 0, i, S, slen)) {
            cout << slen - i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
