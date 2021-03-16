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
    int A, B;
    cin >> A >> B;

    int kokei = A + B;
    int shibou = B;

    if (kokei >= 15 && shibou >= 8) {
        cout << 1 << endl;
    } else if (kokei >= 10 && shibou >= 3) {
        cout << 2 << endl;
    } else if (kokei >= 3) {
        cout << 3 << endl;
    } else {
        cout << 4 << endl;
    }

    return 0;
}
