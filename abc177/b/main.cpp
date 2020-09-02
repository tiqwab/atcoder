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

const int INF = INT_MAX / 2;

int main(void) {
    string S, T;
    cin >> S >> T;
    const int slen = (int) S.size();
    const int tlen = (int) T.size();

    int ans = INF;
    for (int i = 0; i < slen - tlen + 1; i++) {
        int cnt = 0;
        for (int j = 0; j < tlen; j++) {
            if (S[i + j] != T[j]) {
                cnt++;
            }
        }
        chmin(ans, cnt);
    }

    cout << ans << endl;

    return 0;
}
