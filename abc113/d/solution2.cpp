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

bool check(int bits) {
    int prev = bits % 2;
    bits >>= 1;
    while (bits != 0) {
        int cur = bits % 2;
        if (prev == 1 && cur == 1) {
            return false;
        }
        prev = cur;
        bits >>= 1;
    }
    return true;
}

void solve(const int H, const int W, const int K) {
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            for (int bits = 0; bits < (1 << max(0, (W - 1))); bits++) {
                // left is 1

                if (!check(bits)) continue;
                mint v = dp[i][j];
                // printf("i: %d, j: %d, bits: %x, v: %lld\n", i, j, bits, v.x);

                bool left_or_right = false;

                if (j > 1 && (bits & (1 << (j - 2)))) {
                    // go left
                    dp[i + 1][j - 1] += v;
                    left_or_right = true;
                }
                if (j < W && (bits & (1 << (j - 1)))) {
                    // go right
                    dp[i + 1][j + 1] += v;
                    left_or_right = true;
                }
                if (!left_or_right) {
                    // go down
                    dp[i + 1][j] += v;
                }
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
