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
    string A, B;
    cin >> A >> B;

    int sum_a = 0, sum_b = 0;

    for (int i = 0; i < 3; i++) {
        sum_a += A[i] - '0';
        sum_b += B[i] - '0';
    }

    cout << max(sum_a, sum_b) << endl;

    return 0;
}
