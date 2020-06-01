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

const ll MOD = 998244353LL;

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

vector<int> as;

// dp[i][j]: the number of groups which use 1 to i-th items and sum is j
vector<vector<mint>> dp1;
// dp[i]: the answer for i
vector<mint> dp2;

void solve(const int N, const int S) {
    for (int i = 1; i <= N; i++) {
        for (int j = S; j >= 0; j--) {
            dp1[i][j] += dp1[i - 1][j];
            if (j + as[i] <= S) {
                dp1[i][j + as[i]] += dp1[i][j];
                dp2[j + as[i]] += dp2[j];
            }
            dp2[j] *= 2;
        }
    }
}

int main(void) {
    int N, S;
    cin >> N >> S;

    as.resize(N + 1, 0);
    for (int i = 0; i < N; i++) {
        cin >> as[i + 1];
    }

    dp1.resize(N + 1, vector<mint>(S + 1, 0));
    dp1[0][0] = 1;

    dp2.resize(S + 1, 0);
    dp2[0] = 1;

    solve(N, S);

    // printf("dp1: \n");
    // for (int i = 0; i <= N; i++) {
    //     for (int j = 0; j <= S; j++) {
    //         cout << dp1[i][j].x << " ";
    //     }
    //     cout << endl;
    // }

    // printf("dp2: \n");
    // for (int j = 0; j <= S; j++) {
    //     cout << dp2[j].x << " ";
    // }
    // cout << endl;

    cout << dp2[S].x << endl;

    return 0;
}
