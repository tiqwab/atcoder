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

const ll MOD = 1000000007;

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

vector<vector<char>> board;
vector<vector<mint>> dp;
vector<mint> h_acc;
map<int, mint> d_acc; // for diagonal

int main(void) {
    int H, W;
    cin >> H >> W;

    board.resize(H, vector<char>(W));
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            char c;
            cin >> c;
            board[h][w] = c;
        }
    }

    dp.resize(H + 1, vector<mint>(W + 1, 0));
    dp[H - 1][W - 1] = 1;
    h_acc.resize(W, 0);

    for (int h = H - 1; h >= 0; h--) {
        mint w_acc = 0;
        for (int w = W - 1; w >= 0; w--) {
            if (board[h][w] == '#') {
                w_acc = 0;
                h_acc[w] = 0;
                d_acc[h - w] = 0;
                dp[h][w] = 0;
                continue;
            }
            dp[h][w] += w_acc;
            dp[h][w] += h_acc[w];
            dp[h][w] += d_acc[h - w];
            w_acc += dp[h][w];
            h_acc[w] += dp[h][w];
            d_acc[h - w] += dp[h][w];
        }
    }

#ifdef DEBUG
    printf("dp: \n");
    for (int h = 0; h <= H; h++) {
        for (int w = 0; w <= W; w++) {
            printf("%5lld ", dp[h][w].x);
        }
        printf("\n");
    }
    printf("\n");
#endif

    cout << dp[0][0].x << endl;

    return 0;
}
