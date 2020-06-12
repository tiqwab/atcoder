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
    int slen = (int) S.size();
    int K;
    cin >> K;

    set<string> se;
    for (int i = 0; i < slen; i++) {
        string acc = "";
        for (int j = i; j < min(slen, i + 5); j++) {
            acc += S[j];
            se.insert(acc);
        }
    }

    // for (auto s : se) {
    //     cout << s << endl;
    // }

    int i = 0;
    for (auto x : se) {
        i++;
        // cout << x << endl;
        if (i == K) {
            cout << x << endl;
            break;
        }
    }

    return 0;
}
