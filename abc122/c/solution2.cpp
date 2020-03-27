#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

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
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    int slen = (int) S.size();

    vector<int> acc(slen + 1, 0);
    {
        for (int i = 0; i < slen; i++) {
            acc[i + 1] = acc[i];
            if (S[i] == 'A' && S[i + 1] == 'C') {
                acc[i + 1]++;
            }
        }
    }

    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        cout << acc[r] - acc[l] << endl;
    }

    return 0;
}
