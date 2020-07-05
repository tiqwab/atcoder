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
    int A, B, K;
    cin >> A >> B >> K;

    set<int> ans;
    for (int i = A; i <= min(A + (K - 1), B); i++) {
        ans.insert(i);
    }
    for (int i = B; i >= max(A, B - (K - 1)); i--) {
        ans.insert(i);
    }

    for (auto x : ans) {
        cout << x << endl;
    }

    return 0;
}
