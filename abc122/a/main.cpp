#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

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
    char b;
    cin >> b;

    if (b == 'A') {
        cout << "T" << endl;
    } else if (b == 'C') {
        cout << "G" << endl;
    } else if (b == 'G') {
        cout << "C" << endl;
    } else {
        cout << "A" << endl;
    }

    return 0;
}
