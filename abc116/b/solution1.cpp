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

const int MAX_A = 1000000;
const int INF = INT_MAX / 2;

vector<int> memo[MAX_A + 1];

int f(const int x) {
    if (x % 2 == 0) {
        return x / 2;
    } else {
        return x * 3 + 1;
    }
}

int main(void) {
    int s;
    cin >> s;

    memo[s].push_back(1);

    int prev = s;
    for (int i = 2; i <= MAX_A; i++) {
        int v = f(prev);
        memo[v].push_back(i);
        prev = v;
    }

    int ans = INF;
    for (int i = 1; i <= MAX_A; i++) {
        if ((int) memo[i].size() < 2) continue;
        chmin(ans, memo[i][1]);
    }

    cout << ans << endl;

    return 0;
}
