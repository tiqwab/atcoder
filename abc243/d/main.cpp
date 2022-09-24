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
    ll N, X;
    cin >> N >> X;
    string S;
    cin >> S;

    vector<char> acc;

    for (int i = 0; i < N; i++) {
        const char move = S[i];
        if (move == 'U') {
            // 'U'
            if (acc.size() > 0 && acc[acc.size() - 1] != 'U') {
                acc.pop_back();
            } else {
                acc.push_back(move);
            }
        } else if (move == 'L') {
            // 'L'
            acc.push_back(move);
        } else {
            // 'R'
            acc.push_back(move);
        }
    }

    ll cur = X;
    for (auto move : acc) {
        if (move == 'U') {
            // 'U'
            cur = cur / 2;
        } else if (move == 'L') {
            // 'L'
            cur = cur * 2;
        } else {
            // 'R'
            cur = cur * 2 + 1;
        }
    }

    cout << cur << endl;
    return 0;
}
