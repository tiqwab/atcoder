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

/*
 * ref. http://drken1215.hatenablog.com/entry/2018/06/08/210000
 *
 * usage:
 *
 * Combination *c;
 * 
 * const int MOD = 1000000007;
 * const int MAX_N = 100000;
 * 
 * int main(void) {
 *     int n, k;
 *     cin >> n >> k;
 *     c = new Combination(2 * MAX_N, MOD);
 *     cout << c->com(n + k - 1, k) << endl;
 *     delete(c);
 *     return 0;
 * }
 */
class Combination {
    public:
        const int max;
        const int mod;
        vector<ll> fac, finv, inv;

        Combination(int max, int mod) : max(max), mod(mod), fac(max), finv(max), inv(max) {
            init();
        }

        ll com(int n, int k) {
            if (n < k) return 0LL;
            if (n < 0 || k < 0) return 0LL;
            // return (fac[n] * ((finv[k] * finv[n - k]) % mod)) % mod;
            return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
        }

    private:
        void init() {
            fac[0] = fac[1] = 1;
            finv[0] = finv[1] = 1;
            inv[1] = 1;
            for (int i = 2; i < max; i++){
                fac[i] = fac[i - 1] * i % mod;
                inv[i] = mod - inv[mod%i] * (mod / i) % mod;
                finv[i] = finv[i - 1] * inv[i] % mod;
            }
        }
};

Combination *c;

const int MOD = 1000000007;
const int MAX_N = 100000;

vector<ll> x;
vector<ll> v;

// ref. https://atcoder.jp/contests/dwacon6th-prelims/submissions/9421616
int main(void) {
    // use combination library just for fac and finv...
    c = new Combination(2 * MAX_N, MOD);

    ll N;
    cin >> N;

    x.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }

    // v[1] = 1! * (1) = 1
    // v[2] = 2! * (1 + 1/2) = 3 = 2 * v[1] + 1!
    // v[3] = 3! * (1 + 1/2 + 1/3) = 11 = 3 * v[2] + 2!
    // v[4] = 4! * (1 + 1/2 + 1/3 + 1/4) = 50 = 4 * v[3] + 3!
    // ...
    // v[n] = n * v[n - 1] + (n - 1)!
    v.resize(MAX_N + 1, 0);
    for (int i = 1; i <= MAX_N; i++) {
        v[i] = (1LL * i * v[i - 1] + c->fac[i - 1]) % MOD;
    }

    ll ans = 0;
    for (int i = 1; i <= N - 1; i++) {
        ll val = v[i];
        val = val * c->fac[N - 1] % MOD;
        val = val * c->finv[i] % MOD;
        ans = (ans + (val * (x[i] - x[i - 1]) % MOD)) % MOD;
    }

    cout << ans << endl;

    delete(c);
    return 0;
}
