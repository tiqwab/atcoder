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

// improve the same logic as solution1.cpp
int main(void) {
    int n;
    cin >> n;

    map<int, int> ma;
    map<int, int> mb;

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        if (i % 2 == 0) {
            ma[v]++;
        } else {
            mb[v]++;
        }
    }

    // {count, number}
    vector<pair<int, int>> va;
    for (auto &p : ma) {
        va.push_back({p.second, p.first});
    }
    va.push_back({0, -1}); // sentinel
    sort(va.begin(), va.end());
    reverse(va.begin(), va.end());

    // {count, number}
    vector<pair<int, int>> vb;
    for (auto &p : mb) {
        vb.push_back({p.second, p.first});
    }
    vb.push_back({0, -1}); // sentinel
    sort(vb.begin(), vb.end());
    reverse(vb.begin(), vb.end());

    int ans;
    if (va[0].second != vb[0].second) {
        // input2.txt
        ans = n / 2 - va[0].first + n / 2 - vb[0].first;
    } else {
        // input3.txt, input4.txt, input5.txt, input6.txt
        ans = min(n / 2 - va[0].first + n / 2 - vb[1].first, n / 2 - va[1].first + n / 2 - vb[0].first);
    }

    cout << ans << endl;

    return 0;
}
