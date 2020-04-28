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

int div_round_up(int x, int div) {
    return (x + div - 1) / div;
}

int main(void) {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int m = div_round_up(A, D);
    int n = div_round_up(C, B);

    if (m >= n) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
