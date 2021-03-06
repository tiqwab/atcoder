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
    char S, T;
    cin >> S >> T;

    if (S == 'Y') {
        if (T >= 'a' && T <= 'z') {
            T -= 32;
        }
        cout << T << endl;
    } else {
        cout << T << endl;
    }

    return 0;
}
