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

    vector<int> as;
    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    vector<ll> rems(200, 0);
    for (auto a : as) {
        rems[a % 200]++;
    }

    ll ans = 0;
    for (auto r : rems) {
        if (r <= 1) {
            continue;
        }
        ans += r * (r - 1) / 2;
    }

    cout << ans << endl;

    return 0;
}
