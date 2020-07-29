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
    int A, B, C, K;
    cin >> A >> B >> C >> K;

    int cnt = 0;
    while (A >= B) {
        B *= 2;
        cnt++;
    }
    while (B >= C) {
        C *= 2;
        cnt++;
    }

    // cout << cnt << endl;
    if (cnt <= K) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
