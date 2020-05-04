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
    int K, A, B;
    cin >> K >> A >> B;
    bool ok = false;
    for (int i = 1; i <= 1000; i++) {
        int x = K * i;
        if (A <= x && x <= B) {
            ok = true;
            break;
        }
    }
    if (ok) {
        cout << "OK" << endl;
    } else {
        cout << "NG" << endl;
    }
    return 0;
}
