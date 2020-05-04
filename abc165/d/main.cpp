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
    ll A, B, N;
    cin >> A >> B >> N;

    if (B <= N) {
        cout << (A * (B - 1)) / B - A * ((B - 1) / B) << endl;
    } else {
        cout << A * N / B - A * (N / B) << endl;
    }

    return 0;
}
