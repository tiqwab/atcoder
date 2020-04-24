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

    vector<int> counter(N + 1, 0);
    for (int i = 0; i < N - 1; i++) {
        int x;
        cin >> x;
        counter[x]++;
    }

    for (int i = 1; i <= N; i++) {
        cout << counter[i] << endl;
    }

    return 0;
}
