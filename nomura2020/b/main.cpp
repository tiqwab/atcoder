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

    string ans;

    for (int i = 0; i < slen; i++) {
        if (S[i] == '?') {
            // if (i < slen - 1 && S[i + 1] == 'D') {
            //     ans.push_back('P');
            // } else {
            //     ans.push_back('D');
            // }
            ans.push_back('D');
        } else {
            ans.push_back(S[i]);
        }
    }

    cout << ans << endl;

    return 0;
}
