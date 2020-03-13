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

map<char, vector<int>> counter;

int main(void) {
    string s, t;
    cin >> s >> t;
    const int slen = (int) s.size();
    const int tlen = (int) t.size();

    for (int i = 0; i < slen; i++) {
        counter[s[i]].push_back(i);
    }

    for (int i = 0; i < tlen; i++) {
        if ((int) counter[t[i]].size() == 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    ll scnt = 0;
    int si = 0;
    for (auto &tc : t) {
        auto p = lower_bound(counter[tc].begin(), counter[tc].end(), si);
        if (p == counter[tc].end()) {
            si = counter[tc][0] + 1;
            scnt++;
        } else {
            si = *p + 1;
        }
    }

    cout << ll(slen) * ll(scnt) + ll(si) << endl;

    return 0;
}
