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

const int MOD = 1000000007;
const int MAX_N = 100000;

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

// auto mod int
// ref. https://github.com/atcoder-live/library/blob/master/mint.cpp
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%MOD+MOD)%MOD){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += MOD-a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= MOD;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime MOD
  mint inv() const {
    return pow(MOD-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};

Combination *c;

mint solve(const int N, const int K) {
    mint ans;

    int lim = min(N - 1, K);

    for (int m = 0; m <= lim; m++) {
        ans += mint(c->com(N - 1, N - 1 - m)) * mint(c->com(N, m));
    }

    return ans;
}

int main(void) {
    int n, k;
    cin >> n >> k;

    c = new Combination(10 * MAX_N, MOD);

    cout << solve(n, k).x << endl;

    delete(c);
    return 0;
}
