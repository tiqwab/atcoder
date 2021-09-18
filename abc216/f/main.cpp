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

const int MAX_N = 5000;
const int MAX_A = 5000;
const ll MOD =  998244353;

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

vector<pair<int, int>> xs;

vector<mint> dp;
vector<bool> used;

int main(void) {
    int N;
    cin >> N;

    xs.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> xs[i].first;
    }
    for (int i = 0; i < N; i++) {
        cin >> xs[i].second;
    }
    sort(xs.begin(), xs.end());

    dp.resize(MAX_A * 2 + 10, 0);
    dp[0] = 1;

    used.resize(MAX_A * 2 + 10, false);
    used[0] = true;

    mint ans = 0;

    for (int i = 0; i < N; i++) {
        const int a = xs[i].first;
        const int b = xs[i].second;

        for (int j = MAX_A; j >= 0; j--) {
            if (used[j]) {
                if (a >= j + b) {
                    ans += dp[j];
                }
                dp[j + b] += dp[j];
                used[j + b] = true;
            }
        }
    }

    cout << ans.x << endl;

    return 0;
}
