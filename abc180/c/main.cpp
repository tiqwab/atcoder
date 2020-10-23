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
    ll N;
    cin >> N;

    vector<ll> ans;
    for (ll i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            if (i * i != N) {
                ans.push_back(i);
                ans.push_back(N / i);
            } else {
                ans.push_back(i);
            }
        }
    }

    sort(ans.begin(), ans.end());
    for (auto x : ans) {
        printf("%lld\n", x);
    }

    return 0;
}
