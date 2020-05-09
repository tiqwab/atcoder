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

set<char> in[26];
set<char> out[26];

int main(void) {
    string S, T;
    cin >> S >> T;
    int len = (int) S.size();

    for (int i = 0; i < len; i++) {
        int cs = S[i] - 'a';
        int ct = T[i] - 'a';
        out[cs].insert((char) ct);
        in[ct].insert((char) cs);
    }

    bool ok = true;
    for (int i = 0; i < 26; i++) {
        // printf("in['%c']: %d\n", (char) ('a' + i), (int) in[i].size());
        if ((int) in[i].size() > 1) {
            ok = false;
        }
    }
    for (int i = 0; i < 26; i++) {
        // printf("out['%c']: %d\n", (char) ('a' + i), (int) out[i].size());
        if ((int) out[i].size() > 1) {
            ok = false;
        }
    }

    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
