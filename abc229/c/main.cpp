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
    int N, W;
    cin >> N >> W;

    vector<pair<ll, int>> cheese;
    for (int i = 0; i < N; i++) {
        ll a;
        int b;
        cin >> a >> b;
        cheese.push_back(make_pair(a, b));
    }
    sort(cheese.begin(), cheese.end());
    reverse(cheese.begin(), cheese.end());

    ll ans = 0;
    int acc_w = 0;
    for (int i = 0; i < (int) cheese.size(); i++) {
        auto p = cheese[i];
        ll v = p.first;
        int w = p.second;
        int use_w = min(w, W - acc_w);
        ans += v * use_w;
        acc_w += use_w;
        if (acc_w >= W) {
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
