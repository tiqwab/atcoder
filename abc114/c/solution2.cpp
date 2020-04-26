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

int pow(int base, int n) {
    assert(n >= 0);
    if (n == 0) return 1;
    else return base * pow(base, n - 1);
}

int cnt = 0;

bool check(ll v) {
    bool appeared[3] = {false, false, false}; // for 3, 5, and 7
    while (v != 0) {
        int d = v % 10;
        if (d == 3) appeared[0] = true;
        if (d == 5) appeared[1] = true;
        if (d == 7) appeared[2] = true;
        v /= 10;
    }
    return appeared[0] && appeared[1] && appeared[2];
}

void solve(ll acc, const ll N) {
    if (acc > N) return;

    if (check(acc)) {
        // printf("acc: %lld\n", acc);
        cnt++;
    }

    solve(acc * 10 + 7, N);
    solve(acc * 10 + 5, N);
    solve(acc * 10 + 3, N);
}

// based on a solution of editorial.pdf
int main(void) {
    int N;
    cin >> N;
    solve(0, N);
    cout << cnt << endl;
    return 0;
}
