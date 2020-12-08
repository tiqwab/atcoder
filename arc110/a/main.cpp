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

vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

map<int, int> prime_factors(int x) {
    map<int, int> ans;
    for (auto p : primes) {
        while (x % p == 0) {
            ans[p]++;
            x /= p;
        }
        if (x == 1) {
            break;
        }
    }
    return ans;
}

int main(void) {
    int N;
    cin >> N;

    map<int, int> acc;

    for (int i = 2; i <= 30; i++) {
        map<int, int> pf = prime_factors(i);

#ifdef DEBUG
        printf("for %d\n", i);
        for (auto p : pf) {
            printf("  %d: %d\n", p.first, p.second);
        }
#endif

        for (auto p : pf) {
            if (acc[p.first] < p.second) {
                acc[p.first] = p.second;
            }
        }
    }

    ll ans = 1;
    for (auto p : acc) {
        for (int i = 0; i < p.second; i++) {
            ans *= p.first;
        }
    }
    ans++;

#ifdef DEBUG
    for (int i = 2; i <= 30; i++) {
        cout << ans % i << endl;
    }
#endif

    cout << ans << endl;
    return 0;
}
