#include <algorithm>
#include <iostream>
#include <vector>

#include <string.h>

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

const int MAX_X = 1000000; // 10 ** 6

int memo[MAX_X + 1];

bool solve(const int x) {
    if (memo[x] == 1) {
        return true;
    } else if (memo[x] == 0) {
        return false;
    }

    if (x < 100) {
        return false;
    }

    if (solve(x - 100) || solve(x - 101) || solve(x - 102) || solve(x - 103) || solve(x - 104) || solve(x - 105)) {
        memo[x] = 1;
        return true;
    } else {
        memo[x] = 0;
        return false;
    }
}

int main(void) {
    int X;
    cin >> X;

    memset(memo, -1, sizeof(memo));

    memo[100] = 1;
    memo[101] = 1;
    memo[102] = 1;
    memo[103] = 1;
    memo[104] = 1;
    memo[105] = 1;

    if (solve(X)) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }
    
    return 0;
}
