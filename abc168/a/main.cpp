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
    cin >> N;

    int x = N % 10;
    if (x == 2 || x == 4 || x == 5 || x == 7 || x == 9) {
        cout << "hon" << endl;
    } else if (x == 0 || x == 1 || x == 6 || x == 8) {
        cout << "pon" << endl;
    } else {
        cout << "bon" << endl;
    }

    return 0;
}
