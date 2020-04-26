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
    string S;
    cin >> S;

    int ans = 10000;
    int acc = 0;
    for (int i = 0; i < (int) S.size(); i++) {
        int d = S[i] - '0';
        acc = (acc * 10 + d) % 1000;
        // printf("acc: %d\n", acc);
        if (i >= 2) {
            chmin(ans, abs(acc - 753));
        }
    }

    cout << ans << endl;

    return 0;
}
