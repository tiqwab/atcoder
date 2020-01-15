#include <algorithm>
#include <iostream>
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

const ll MOD = 1000000007;

vector<ll> C;
vector<ll> two;

ll solve(const ll N) {
    ll acc = 0;
    for (int i = 1; i <= N; i++) {
        ll l = i - 1;
        ll r = N - i;
        ll k = i;

        ll x = two[r];
        if (r != 0) x = (x + two[r - 1] * r) % MOD; // ???
        x = x * two[l] % MOD;
        x = x * C[k] % MOD;
        acc = (acc + x) % MOD;
        // printf("x: %lld, acc: %lld\n", x, acc);
    }
    return acc * two[N] % MOD;
}

int main(void) {
    ll N;
    cin >> N;

    C.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> C[i];
    }
    sort(C.begin() + 1, C.end());

    two.resize(N + 1);
    two[0] = 1LL;
    for (int i = 1; i <= N; i++) {
        two[i] = two[i - 1] * 2 % MOD;
    }

    cout << solve(N) << endl;

    return 0;
}
