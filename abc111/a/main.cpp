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
    string s;
    cin >> s;

    for (int i = 0; i < 3; i++) {
        if (s[i] == '1') {
            cout << "9";
        } else {
            cout << "1";
        }
    }
    cout << endl;

    return 0;
}
