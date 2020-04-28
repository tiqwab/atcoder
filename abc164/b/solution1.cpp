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
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    while (1) {
        C -= B;
        if (C <= 0) {
            cout << "Yes" << endl;
            break;
        }

        A -= D;
        if (A <= 0) {
            cout << "No" << endl;
            break;
        }
    }

    return 0;
}
