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

// based on editorial.pdf (or video)
int main(void) {
    vector<int> cs(9);
    for (int i = 0; i < 9; i++) {
        cin >> cs[i];
    }

    vector<int> cand_as(3);
    vector<int> cand_bs(3);
    cand_as[0] = 0;
    cand_bs[0] = cs[0] - cand_as[0];
    cand_bs[1] = cs[1] - cand_as[0];
    cand_bs[2] = cs[2] - cand_as[0];
    cand_as[1] = cs[3] - cand_bs[0];
    cand_as[2] = cs[6] - cand_bs[0];

    bool ok = true;
    for (int i = 0; i < 9; i++) {
        if (cs[i] != cand_as[i / 3] + cand_bs[i % 3]) {
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
