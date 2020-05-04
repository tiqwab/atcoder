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

    int x = (A + K - 1) / K;
    int y = B / K;
    if (y - x >= 0) {
        cout << "OK" << endl;
    } else {
        cout << "NG" << endl;
    }

    return 0;
}
