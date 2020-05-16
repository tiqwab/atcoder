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
    int N, K;
    cin >> N >> K;

    if (K % 2 != 0) {
        ll a = N / K;
        cout << a * a * a << endl;
    } else {
        ll a = N / K;
        ll b = (N - K / 2) / K;
        if (N - K / 2 >= 0) {
            b++;
        }
        cout << a * a * a + b * b * b << endl;
    }

    return 0;
}
