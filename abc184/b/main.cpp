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
    int N, X;
    cin >> N >> X;

    int point = X;
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        if (c == 'o') {
            point++;
        } else {
            if (point > 0) {
                point--;
            }
        }
    }

    cout << point << endl;
    return 0;
}
