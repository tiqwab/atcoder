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

const ll MOD = 998244353;

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

const int MAX_K = 1000 * 1000 + 5;

mint memo[2][2][MAX_K];

int main(void) {
    ll H, W, K;
    cin >> H >> W >> K;
    ll h1, w1, h2, w2;
    cin >> h1 >> w1 >> h2 >> w2;

    bool is_same_h = h1 == h2;
    bool is_same_w = w1 == w2;

    memo[is_same_h][is_same_w][0] = 1;
    for (ll k = 0; k < K; k++) {
        // false, false
        memo[false][false][k + 1] += memo[false][false][k] * (H + W - 4);
        memo[false][true][k + 1] += memo[false][false][k];
        memo[true][false][k + 1] += memo[false][false][k];

        // false, true
        memo[false][false][k + 1] += memo[false][true][k] * (W - 1);
        memo[false][true][k + 1] += memo[false][true][k] * (H - 2);
        memo[true][true][k + 1] += memo[false][true][k];

        // true, false
        memo[false][false][k + 1] += memo[true][false][k] * (H - 1);
        memo[true][false][k + 1] += memo[true][false][k] * (W - 2);
        memo[true][true][k + 1] += memo[true][false][k];

        // true, true
        memo[false][true][k + 1] += memo[true][true][k] * (H - 1);
        memo[true][false][k + 1] += memo[true][true][k] * (W - 1);
    }

    printf("%lld\n", memo[true][true][K].x);

    return 0;
}
