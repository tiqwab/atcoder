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
    int K;
    string S;
    cin >> K >> S;
    int slen = (int) S.size();

    if (slen <= K) {
        cout << S << endl;
    } else {
        for (int i = 0; i < K; i++) {
            cout << S[i];
        }
        cout << "..." << endl;
    }

    return 0;
}
