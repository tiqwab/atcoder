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

vector<ll> primes;

void calc_primes() {
    vector<bool> xs(1000 * 1000 + 1, false);
    for (int i = 2; i < 1000 * 1000; i++) {
        if (xs[i]) {
            continue;
        }
        primes.push_back(i);
        for (int j = i; j < 1000 * 1000; j += i) {
            xs[j] = true;
        }
    }

    sort(primes.begin(), primes.end());
}

int main(void) {
    ll N;
    cin >> N;

    calc_primes();

#ifdef DEBUG
    for (auto p : primes) {
        printf("%lld\n", p);
    }
#endif

    ll ans = 0;

    for (int i = 0; i < (int) primes.size(); i++) {
        ll p = primes[i];

        int left = i;
        int right = (int) primes.size() - 1;
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            ll q = primes[mid];
            if (q * q * q > (N / p)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        ans += left - i;
    }

    printf("%lld\n", ans);

    return 0;
}
