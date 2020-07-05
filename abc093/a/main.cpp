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

    bool ok[3] = {false, false, false};

    for (int i = 0; i < 3; i++) {
        char c = S[i];
        if (c == 'a') {
            ok[0] = true;
        } else if (c == 'b') {
            ok[1] = true;
        } else if (c == 'c') {
            ok[2] = true;
        }
    }

    if (ok[0] && ok[1] && ok[2]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
