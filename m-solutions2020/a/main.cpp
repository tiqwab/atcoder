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
    int X;
    cin >> X;
    if (X >= 1800) {
        cout << 1 << endl;
    } else if (X >= 1600) {
        cout << 2 << endl;
    } else if (X >= 1400) {
        cout << 3 << endl;
    } else if (X >= 1200) {
        cout << 4 << endl;
    } else if (X >= 1000) {
        cout << 5 << endl;
    } else if (X >= 800) {
        cout << 6 << endl;
    } else if (X >= 600) {
        cout << 7 << endl;
    } else {
        cout << 8 << endl;
    }
    return 0;
}
