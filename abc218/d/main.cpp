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
    int N;
    cin >> N;

    // points[y] = xs
    map<int, set<int>> points;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        points[y].insert(x);
    }


    ll ans = 0;

    for (auto pss1 : points) {
        for (auto pss2 : points) {
            if (pss1.first == pss2.first) {
                continue;
            }

            auto ps1 = pss1.second;
            auto ps2 = pss2.second;
            map<int, int> counter;
            for (auto p : ps1) {
                counter[p]++;
            }
            for (auto p : ps2) {
                counter[p]++;
            }

            int cnt = 0;
            for (auto pair : counter) {
                if (pair.second == 2) {
                    cnt++;
                }
            }
            ans += cnt * (cnt - 1) / 2;
        }
    }

    cout << ans / 2 << endl;

    return 0;
}
