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
bool used[2][2][MAX_K];

mint dfs(bool is_same_x, bool is_same_y, const ll cur_k, const ll H, const ll W) {
    if (used[is_same_x][is_same_y][cur_k]) {
        return memo[is_same_x][is_same_y][cur_k];
    }

    mint ans = 0;

    if (cur_k == 1) {
        if (is_same_x && is_same_y) {
            ans = 0;
        } else if (is_same_x || is_same_y) {
            ans = 1;
        } else {
            ans = 0;
        }
    } else if (cur_k == 2) {
        if (is_same_x && is_same_y) {
            ans = (H + W - 2);
        } else if (is_same_x) {
            ans = H - 2;
        } else if (is_same_y) {
            ans = W - 2;
        } else {
            ans = 2;
        }
    } else {
        if (is_same_x && is_same_y) {
            ans += dfs(false, true, cur_k - 1, H, W) * (W - 1);
            ans += dfs(true, false, cur_k - 1, H, W) * (H - 1);
        } else if (is_same_x) {
            ans += dfs(true, true, cur_k - 1, H, W);
            ans += dfs(true, false, cur_k - 1, H, W) * (H - 2);
            ans += dfs(false, false, cur_k - 1, H, W) * (W - 1);
        } else if (is_same_y) {
            ans += dfs(true, true, cur_k - 1, H, W);
            ans += dfs(false, true, cur_k - 1, H, W) * (W - 2);
            ans += dfs(false, false, cur_k - 1, H, W) * (H - 1);
        } else {
            ans += dfs(true, false, cur_k - 1, H, W);
            ans += dfs(false, true, cur_k - 1, H, W);
            ans += dfs(false, false, cur_k - 1, H, W) * (H + W - 4);
        }
    }

    memo[is_same_x][is_same_y][cur_k] = ans;
    used[is_same_x][is_same_y][cur_k] = true;
    return ans;
}

int main(void) {
    ll H, W, K;
    cin >> H >> W >> K;
    ll x1, y1, x2, y2;
    cin >> y1 >> x1 >> y2 >> x2;

    bool is_same_x = x1 == x2;
    bool is_same_y = y1 == y2;

    for (int k = 1; k < K; k++) {
        dfs(is_same_x, is_same_y, k, H, W);
    }
    printf("%lld\n", dfs(is_same_x, is_same_y, K, H, W).x);

    return 0;
}
