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
    int A, B, C;
    cin >> A >> B >> C;

    if (A < B) {
        cout << "Aoki" << endl;
    } else if (A > B) {
        cout << "Takahashi" << endl;
    } else {
        if (C == 0) {
            cout << "Aoki" << endl;
        } else {
            cout << "Takahashi" << endl;
        }
    }

    return 0;
}
