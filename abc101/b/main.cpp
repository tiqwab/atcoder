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
    cin >> S;

    int n = 0;
    for (int i = 0; i < (int) S.size(); i++) {
        int d = S[i] - '0';
        n = n * 10 + d;
    }
    // printf("n: %d\n", n);

    int acc = 0;
    for (int i = 0; i < (int) S.size(); i++) {
        int d = S[i] - '0';
        acc += d;
    }
    // printf("acc: %d\n", acc);

    if (n % acc == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


    return 0;
}
