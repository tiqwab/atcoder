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

vector<vector<mint>> dp;
vector<vector<char>> marks;
vector<vector<int>> acc_empty;

int main(void) {
    int H, W, K;
    cin >> H >> W >> K;

    marks.resize(H, vector<char>(W, ' '));
    for (int i = 0; i < K; i++) {
        int h, w;
        char c;
        cin >> h >> w >> c;
        h--;
        w--;
        marks[h][w] = c;
    }

    acc_empty.resize(H + 1, vector<int>(W + 1, 0));
    for (int h = 1; h <= H; h++) {
        for (int w = 1; w <= W; w++) {
            if (marks[h - 1][w - 1] == ' ') {
                acc_empty[h][w] = 1;
            }
            acc_empty[h][w] += acc_empty[h - 1][w] + acc_empty[h][w - 1] - acc_empty[h - 1][w - 1];
        }
    }
#ifdef DEBUG
    printf("acc_empty: \n");
    for (int h = 0; h <= H; h++) {
        for (int w = 0; w <= W; w++) {
            cout << acc_empty[h][w] << " ";
        }
        cout << endl;
    }
    cout << endl;
#endif

    const mint inv3 = mint(3).inv();

    const int max_empty_num = acc_empty[H][W];
    dp.resize(H + 1, vector<mint>(W + 1, 0));
    dp[0][0] = mint(3).pow(max_empty_num);

    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            const char mark = marks[h][w];
            mint x = dp[h][w];
            if (mark == 'R') {
                dp[h][w + 1] += x;
            } else if (mark == 'D') {
                dp[h + 1][w] += x;
            } else if (mark == 'X') {
                dp[h + 1][w] += x;
                dp[h][w + 1] += x;
            } else {
                x = dp[h][w] * inv3;

                // 'D'
                dp[h + 1][w] += x;

                // 'R'
                dp[h][w + 1] += x;

                // 'X'
                dp[h + 1][w] += x;
                dp[h][w + 1] += x;
            }
        }
    }

#ifdef DEBUG
    printf("dp: \n");
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            cout << dp[h][w].x << " ";
        }
        cout << endl;
    }
    cout << endl;
#endif

    cout << dp[H - 1][W - 1].x << endl;

    return 0;
}
