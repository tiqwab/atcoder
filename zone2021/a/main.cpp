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
    const int slen = (int) S.size();

    int cnt = 0;
    for (int i = 0; i < slen - 3; i++) {
        if (S[i] == 'Z' && S[i + 1] == 'O' && S[i + 2] == 'N' && S[i + 3] == 'e') {
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}
