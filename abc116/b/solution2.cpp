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

const int MAX_A = 1000000;
const int INF = INT_MAX / 2;

int memo[MAX_A + 1];

int f(const int x) {
    if (x % 2 == 0) {
        return x / 2;
    } else {
        return x * 3 + 1;
    }
}

int main(void) {
    int s;
    cin >> s;

    memo[s] = 1;

    int prev = s;
    for (int i = 2; i <= MAX_A; i++) {
        int v = f(prev);
        if (memo[v] != 0) {
            cout << i << endl;
            return 0;
        }
        memo[v] = i;
        prev = v;
    }

    return 0;
}
