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

pair<int, int> rotate90(const int x, const int y) {
    return {-y, x};
}

int main(void) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    pair<int, int> p4 = rotate90(x2 - x1, y2 - y1);
    int x4 = p4.first + x1, y4 = p4.second + y1;

    pair<int, int> p3 = rotate90(x1 - x4, y1 - y4);
    int x3 = p3.first + x4, y3 = p3.second + y4;

    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;

    return 0;
}
