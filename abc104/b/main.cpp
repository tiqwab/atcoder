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

    if (S[0] != 'A') {
        cout << "WA" << endl;
        return 0;
    }

    if (!( ('a' <= S[1] && S[1] <= 'z') && ('a' <= S.back() && S.back() <= 'z') )) {
        cout << "WA" << endl;
        return 0;
    }

    int count_C = 0;
    for (int i = 2; i < (int) S.size() - 1; i++) {
        if (S[i] == 'C') {
            count_C++;
        } else if ('A' <= S[i] && S[i] <= 'Z') {
            cout << "WA" << endl;
            return 0;
        }
    }

    if (count_C == 1) {
        cout << "AC" << endl;
        return 0;
    } else {
        cout << "WA" << endl;
        return 0;
    }
}
