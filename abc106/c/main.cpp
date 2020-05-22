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
    ll K;
    cin >> S >> K;

    char d = '1';
    for (int i = 0; i < K; i++) {
        if (S[i] != '1') {
            d = S[i];
            break;
        }
    }

    cout << d << endl;

    return 0;
}
