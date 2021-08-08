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

const ll MOD = 1000 * 1000 * 1000 + 7;

vector<vector<int>> poss(8, vector<int>());

int main(void) {
    string S;
    cin >> S;

    // initialize poss
    {
        map<char, int> c_to_idx;
        const string chokudai = "chokudai";

        for (int i = 0; i < (int) chokudai.size(); i++) {
            c_to_idx[chokudai[i]] = i;
        }

        for (int i = 0; i < (int) S.size(); i++) {
            const char c = S[i];
            if (c_to_idx.find(c) == c_to_idx.end()) {
                continue;
            }
            poss[c_to_idx[c]].push_back(i);
        }
    }


    // {pos, cnt}
    map<int, ll> acc;

    // for the first 'c'
    for (auto pos : poss[0]) {
        acc[pos] = 1;
    }

    for (int i = 1; i < 8; i++) {
        int prev_idx = 0;
        ll cnt = 0;
        map<int, ll> tmp;

        for (auto cur_pos : poss[i]) {
            while (prev_idx < (int) poss[i - 1].size() && cur_pos > poss[i - 1][prev_idx]) {
                cnt = (cnt + acc[poss[i - 1][prev_idx]]) % MOD;
                prev_idx += 1;
            }
            tmp[cur_pos] = cnt;
        }

        swap(acc, tmp);
    }

    ll ans = 0;
    for (auto p : acc) {
        ans = (ans + p.second) % MOD;
    }
    cout << ans << endl;

    return 0;
}
