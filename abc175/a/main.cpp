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

    if (S == "SSS") {
        cout << 0 << endl;
    } else if (S == "RSS") {
        cout << 1 << endl;
    } else if (S == "SRS") {
        cout << 1 << endl;
    } else if (S == "SSR") {
        cout << 1 << endl;
    } else if (S == "RRS") {
        cout << 2 << endl;
    } else if (S == "RSR") {
        cout << 1 << endl;
    } else if (S == "SRR") {
        cout << 2 << endl;
    } else if (S == "RRR") {
        cout << 3 << endl;
    } else {
        cout << "illegal input: " + S << endl;
        abort();
    }

    return 0;
}
