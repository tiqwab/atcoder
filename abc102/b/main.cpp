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

    vector<int> as(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }
    sort(as.begin(), as.end());

    int len = (int) as.size();
    cout << as[len - 1] - as[0] << endl;

    return 0;
}
