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
    int A, B, K;
    cin >> A >> B >> K;

    if ((K - 1) * 2 >= B - A) {
        for (int i = A; i <= B; i++) {
            cout << i << endl;
        }
    } else {
        for (int i = A; i < A + K; i++) {
            cout << i << endl;
        }
        for (int i = B - K + 1; i <= B; i++) {
            cout << i << endl;
        }
    }

    return 0;
}
