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
    set<char> se;
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        se.insert(c);
    }

    if ((int) se.size() == 3) {
        cout << "Three" << endl;
    } else if ((int) se.size() == 4) {
        cout << "Four" << endl;
    } else {
        printf("illegal size: %d\n", (int) se.size());
        return 1;
    }

    return 0;
}
