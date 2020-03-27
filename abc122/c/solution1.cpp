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

    vector<int> idxes;
    {
        char prev = ' ';
        for (int i = 0; i < N; i++) {
            if (prev == 'A' && S[i] == 'C') {
                idxes.push_back(i - 1);
            }
            prev = S[i];
        }
    }

    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        auto low = lower_bound(idxes.begin(), idxes.end(), l);
        auto high = lower_bound(idxes.begin(), idxes.end(), r);
        cout << high - low << endl;
    }

    return 0;
}
