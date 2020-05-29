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
    string S, T;
    cin >> S >> T;

    int len = (int) S.size();

    for (int start = 0; start < len; start++) {
        bool ok = true;
        // printf("start: %d\n", start);
        for (int i = 0; i < len; i++) {
            int pos = (start + i) % len;
            // printf("%c, %c\n", S[i], T[pos]);
            if (S[i] != T[pos]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
