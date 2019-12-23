#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

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

void calc_prime_factors(ll N, map<ll, ll> &m) {
    m[1] = 1;
    for (int i = 2; i * i <= N; i++) {
        while (N % i == 0) {
            m[i]++;
            N /= i;
        }
    }
}

int main(void) {
    ll N;
    cin >> N;

    if (N % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }

    ll num_five1 = 0;
    {
        ll acc = 2 * 5;
        while (acc <= N) {
            num_five1 += N / acc;
            acc *= 5;
        }
    }

    // map<ll, ll> m;
    // calc_prime_factors(N, m);
    // ll num_five2 = m[5];

    cout << num_five1 << endl;

    return 0;
}
