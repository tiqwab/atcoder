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

int pow(int base, int n) {
    if (n <= 0) return 1;
    else return base * pow(base, n - 1);
}

int main(void) {
    int D, N;
    cin >> D >> N;

    if (N == 100) N++;
    cout << pow(100, D) * N << endl;

    return 0;
}
