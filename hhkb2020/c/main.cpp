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

const int MAX_N = 200000;

vector<bool> can_use;

int main(void) {
    int N;
    cin >> N;

    can_use.resize(MAX_N + 2, true);
    int cur = 0;

    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        can_use[p] = false;
        while (!can_use[cur]) {
            cur++;
        }
        printf("%d\n", cur);
    }

    return 0;
}
