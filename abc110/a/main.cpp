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
    int A, B, C;
    cin >> A >> B >> C;
    vector<int> xs;
    xs.push_back(A);
    xs.push_back(B);
    xs.push_back(C);
    sort(xs.begin(), xs.end());
    reverse(xs.begin(), xs.end());

    cout << xs[0] * 10 + xs[1] + xs[2] << endl;

    return 0;
}
