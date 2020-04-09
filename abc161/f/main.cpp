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

set<ll> calc_divs_for(const ll N) {
    set<ll> ans;
    for (ll i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            ans.insert(i);
            ans.insert(N / i);
        }
    }
    return ans;
}

ll pow(const ll base, ll n) {
    ll ans = 1;
    while (n > 0) {
        ans *= base;
        n--;
    }
    return ans;
}

int main(void) {
    ll N;
    cin >> N;

    set<ll> ans;

    // for a = 0;
    {
        // printf("a = 0\n");
        set<ll> divs = calc_divs_for(N - 1);
        for (auto &div : divs) {
            // printf("%lld\n", div);
            ans.insert(div);
        }
    }

    // for a = 1;
    {
        // printf("a = 1\n");
        set<ll> divs = calc_divs_for(N);
        for (auto &div : divs) {
            ll x = N / div - 1;
            // printf("%lld\n", div);
            if (x % div == 0) {
                ans.insert(div);
            }
        }
    }

    // for a = n;
    for (ll i = 2; i <= 40; i++) {
        // printf("a = %lld\n", i);
        for (ll j = 1; pow(j, i) <= N; j++) {
            ll v = pow(j, i);
            if (N % v == 0) {
                ll x = N / v - 1;
                if (x % j == 0) {
                    // printf("%lld\n", j);
                    ans.insert(j);
                }
            }
        }
    }

    ans.erase(1);
    cout << ans.size() << endl;

    return 0;
}
