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

map<ll, int> prime_factors(const ll init_n) {
    map<ll, int> ans;
    ll n = init_n;
    for (ll i = 2; i * i <= init_n; i++) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                n /= i;
                cnt++;
            }
            ans[i] = cnt;
        }
    }

    if (n != 1) {
        ans[n]++;
    }

    return ans;
}

int main(void) {
    ll N;
    cin >> N;

    if(N == 1) {
        cout << 0 << endl;
        return 0;
    }

    map<ll, int> factors = prime_factors(N);
    // for (auto &p : factors) {
    //     cout << p.first << ": " << p.second << endl;
    // }

    vector<int> acc;
    for (auto &p : factors) {
        ll prime = p.first;
        int cnt = p.second;
        int x = 0;
        int i = 1;
        for (;;) {
            x += i;
            if (x > cnt) {
                break;
            }
            i++;
        }
        i--;
        acc.push_back(i);
    }

    int ans = 0;
    for (auto x : acc) {
        ans += x;
        // cout << x << endl;
    }

    cout << ans << endl;

    return 0;
}
