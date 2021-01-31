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
    int N;
    ll X;
    cin >> N >> X;

    X *= 100;

    ll acc = 0;

    for (int i = 0; i < N; i++) {
        ll V, P;
        cin >> V >> P;
        acc += V * P; 
        if (acc > X) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
