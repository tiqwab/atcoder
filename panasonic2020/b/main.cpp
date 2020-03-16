#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

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
    ll H, W;
    cin >> H >> W;

    if (H == 1 || W == 1){ 
        cout << 1 << endl;
        return 0;
    }

    if (H % 2 == 1 && W % 2 == 1) {
        cout << (H * W / 2) + 1 << endl;
    } else {
        cout << H * W / 2 << endl;
    }

    return 0;
}
