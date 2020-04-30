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

const ll MOD = ll(1e9 + 7);

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

vector<vector<mint>> dp;

// return 1 if n <= 1
mint pats_for_lines(const int n) {
    static map<int, mint> m;
    if (n <= 1) return mint(1);
    if (m.find(n) != m.end()) return m[n];
    mint v(0);
    for (int i = 0; i < (1 << (n - 1)); i++) {
        int x = i;
        bool ok = true;
        int prev = x % 2;
        x >>= 1;
        while (x != 0) {
            int cur = x % 2;
            // printf("x: %d, prev: %d, cur: %d\n", x, prev, cur);
            if (prev == 1 && cur == 1) {
                ok = false;
                break;
            }
            prev = cur;
            x >>= 1;
        }
        if (ok) {
            v += 1;
        }
    }
    // printf("[pats_for_lines] n: %d, x: %lld\n", n, v.x);
    m[n] = v;
    return v;
}

void solve(const int H, const int W, const int K) {
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (j > 1) {
                // go left
                mint v = dp[i][j];

                if (j - 1 == 1) {
                    v *= pats_for_lines(W - 2);
                } else if (j == W) {
                    v *= pats_for_lines(W - 2);
                } else {
                    v *= pats_for_lines((j - 1) - 1);
                    v *= pats_for_lines(W - j);
                }

                dp[i + 1][j - 1] += v;
            }
            if (j < W) {
                // go right
                mint v = dp[i][j];

                if (j + 1 == W) {
                    v *= pats_for_lines(W - 2);
                } else if (j == 1) {
                    v *= pats_for_lines(W - 2);
                } else {
                    v *= pats_for_lines(j - 1);
                    v *= pats_for_lines(W - (j + 1));
                }

                dp[i + 1][j + 1] += v;
            }

            {
                // go down
                mint v = dp[i][j];

                if (j == 1) {
                    v *= pats_for_lines(W - 1);
                } else if (j == W) {
                    v *= pats_for_lines(W - 1);
                } else {
                    v *= pats_for_lines(j - 1);
                    v *= pats_for_lines(W - j);
                }

                dp[i + 1][j] += v;
            }
        }
    }
}

int main(void) {
    int H, W, K;
    cin >> H >> W >> K;

    dp.resize(H + 2, vector<mint>(W + 1, 0));
    dp[1][1] = 1;

    solve(H, W, K);

    // for (int i = 0; i <= H + 1; i++) {
    //     for (int j = 0; j <= W; j++) {
    //         cout << dp[i][j].x << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    cout << dp[H + 1][K].x << endl;

    return 0;
}
