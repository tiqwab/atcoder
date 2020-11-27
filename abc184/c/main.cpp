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
    int r1, c1, r2, c2;
    cin >> r1 >> c1;
    cin >> r2 >> c2;

    if (r1 + c1 > r2 + c2) {
        swap(r1, r2);
        swap(c1, c2);
    }

    if (r1 == r2 && c1 == c2) {
        cout << 0 << endl;
        return 0;
    }

    if (abs(r1 - r2) + abs(c1 - c2) <= 3) {
        cout << 1 << endl;
        return 0;
    }

    if (r1 + c1 == r2 + c2) {
        cout << 1 << endl;
        return 0;
    }

    if (r1 - c1 == r2 - c2) {
        cout << 1 << endl;
        return 0;
    }

    if ((r1 + c1) % 2 == (r2 + c2) % 2) {
        cout << 2 << endl;
        return 0;
    }

    if (abs(r1 - r2) + abs(c1 - c2) <= 6) {
        cout << 2 << endl;
        return 0;
    }

    if ((r1 + c1) - 3 <= (r2 + c2) && (r2 + c2) <= (r1 + c1) + 3) {
        cout << 2 << endl;
        return 0;
    }

    if ((r1 - c1) - 3 <= (r2 - c2) && (r2 - c2) <= (r1 - c1) + 3) {
        cout << 2 << endl;
        return 0;
    }

    cout << 3 << endl;
    return 0;
}
