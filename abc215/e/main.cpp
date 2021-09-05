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

#define convert(c) (((char) (c)) - 'A')

int main(void) {
    int N;
    cin >> N;
    string S;
    cin >> S;

    // dp[i][j][k] is:
    // S の i 番目の数
    // j はすでに使用した数の集合
    // k は最後に使用した数 (0 for 'A', ..., 9 for 'J')
    vector<vector<vector<mint>>> dp(N + 1);
    for (int i = 0; i < (int) dp.size(); i++) {
        dp[i].resize(1 << 10);
        for (int j = 0; j < (int) dp[i].size(); j++) {
            dp[i][j].resize(11, 0);
        }
    }

    for (int i = 1; i <= N; i++) {
        const char c = S[i - 1];
        const char d = convert(c);
        for (int j = 0; j < (1 << 10); j++) {
            for (int k = 0; k < 10; k++) {
                dp[i][j][k] += dp[i - 1][j][k];
                if ((j & (1 << d)) != 0) {
                    // already used
                    if (k == d) {
                        // this is last used one
#ifdef DEBUG
                        if (dp[i - 1][j][k].x > 0) {
                            printf("A: dp[%d][%d][%d] += %lld (dp[%d][%d][%d])\n",
                                    i, j, k, dp[i - 1][j][k].x, i - 1, j, k);
                        }
#endif
                        dp[i][j][k] += dp[i - 1][j][k];
                    } else {
                        // do nothing
                    }
                } else {
#ifdef DEBUG
                    if (dp[i - 1][j][k].x > 0) {
                        printf("C: dp[%d][%d][%d] += %lld (dp[%d][%d][%d])\n",
                                i, j | (1 << d), d, dp[i - 1][j][k].x, i - 1, j, k);
                    }
#endif
                    dp[i][j | (1 << d)][d] += dp[i - 1][j][k];
                }
            }
        }
        dp[i][1 << d][d] += 1;

#ifdef DEBUG
        mint ans = 0;
        for (int j = 0; j < (1 << 10); j++) {
            for (int k = 0; k < 10; k++) {
                if (dp[i][j][k].x > 0) {
                    printf("add %lld from dp[%d][%d][%d]\n", dp[i][j][k].x, i, j, k);
                }
                ans += dp[i][j][k];
            }
        }
        cout << ans.x << endl;
#endif
    }

    mint ans = 0;
    for (int j = 0; j < (1 << 10); j++) {
        for (int k = 0; k < 10; k++) {
            ans += dp[N][j][k];
        }
    }
    cout << ans.x << endl;

    return 0;
}
