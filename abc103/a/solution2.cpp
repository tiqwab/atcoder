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
    vector<int> as(3);
    for (int i = 0; i < 3; i++) {
        cin >> as[i];
    }

    cout << *max_element(as.begin(), as.end()) - *min_element(as.begin(), as.end()) << endl;

    return 0;
}
