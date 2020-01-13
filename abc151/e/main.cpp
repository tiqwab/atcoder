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

vector<ll> A;

ll solve(const ll N, const ll K) {
    ll maxs = 0;
    for (int i = K; i <= N; i++) {
        ll v = A[i] * c->com(i - 1, K - 1);
        // printf("max[%d]: %lld\n", i, v);
        maxs = (maxs + (v % MOD)) % MOD;
    }

    ll mins = 0;
    for (int i = 1; i <= N - K + 1; i++) {
        ll v = A[i] * c->com(N - i, K - 1);
        // printf("min[%d]: %lld\n", i, v);
        mins = (mins + (v % MOD)) % MOD;
    }

    ll ans = (maxs - mins) % MOD;
    if (ans < 0) ans += MOD;
    return ans;
}

int main(void) {
    ll N, K;
    cin >> N >> K;

    A.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    sort(A.begin() + 1, A.end());

    c = new Combination(2 * MAX_N, MOD);

    cout << solve(N, K) << endl;
    // cout << c->com(n + k - 1, k) << endl;

    delete(c);
    return 0;
}
