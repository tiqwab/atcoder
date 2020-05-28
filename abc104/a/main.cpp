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
    int R;
    cin >> R;

    if (R < 1200) {
        cout << "ABC" << endl;
    } else if (R < 2800) {
        cout << "ARC" << endl;
    } else {
        cout << "AGC" << endl;
    }

    return 0;
}
