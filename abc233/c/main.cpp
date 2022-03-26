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

ll dfs(const int cur_i, const ll acc, const vector<vector<ll>> &ass, const int N, const ll X) {
    if (cur_i == N) {
        if (acc == X) {
            return 1;
        } else {
            return 0;
        }
    }

    ll ans = 0;
    for (auto a : ass[cur_i]) {
        if (acc > X / a) {
            continue;
        }
        ans += dfs(cur_i + 1, acc * a, ass, N, X);
    }
    return ans;
}

int main(void) {
    int N;
    ll X;
    cin >> N >> X;

    vector<vector<ll>> ass;
    for (int i = 0; i < N; i++) {
        int L;
        cin >> L;
        vector<ll> as;
        for (int j = 0; j < L; j++) {
            ll a;
            cin >> a;
            as.push_back(a);
        }
        ass.push_back(as);
    }

    printf("%lld\n", dfs(0, 1, ass, N, X));
    return 0;
}
