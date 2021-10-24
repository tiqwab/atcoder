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

vector<ll> calc_cand(vector<int> xs) {
    vector<ll> ans;

    do {
        if (xs[0] != 0) {
            ll v = 0;
            for (auto x : xs) {
                v *= 10;
                v += x;
            }
            ans.push_back(v);
        }
    } while (next_permutation(xs.begin(), xs.end()));

    return ans;
}

int main(void) {
    string S;
    cin >> S;

    const int slen = (int) S.size();

    ll ans = 0;

    for (int i = 0; i < (1 << slen); i++) {
        vector<int> xs;
        vector<int> ys;

        for (int j = 0; j < slen; j++) {
            int d = S[j] - '0';
            if (i & (1 << j)) {
                xs.push_back(d);
            } else {
                ys.push_back(d);
            }
        }
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
        if (xs.size() == 0 || ys.size() == 0) {
            continue;
        }

        vector<ll> cand1 = calc_cand(xs);
        vector<ll> cand2 = calc_cand(ys);
        for (auto a : cand1) {
            for (auto b : cand2) {
#ifdef DEBUG
                printf("%lld %lld\n", a, b);
#endif
                chmax(ans, a * b);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
