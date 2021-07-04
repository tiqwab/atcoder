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

const int MAX_N = 3005;
mint dp[MAX_N][MAX_N];

// ds[i][j] is num of patterns satifying:
//   s[k] % i == j (k < i)
mint ds[MAX_N][MAX_N];

// solution based on YouTube
int main(void) {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> s(n + 1, 0);
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + a[i];
    }

    dp[0][0] = 1;
    ds[1][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j >= 0; j--) {
            mint now;
            // for (int k = 0; k < i; k++) {
            //     if ((s[i] - s[k]) % (j + 1) == 0) {
            //         now += dp[k][j];
            //     }
            // }
            now = ds[j + 1][s[i] % (j + 1)];
            dp[i][j + 1] = now;
            ds[j + 2][s[i] % (j + 2)] += now;
        }
    }

#ifdef DEBUG
    printf("dp: \n");
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j].x << " ";
        }
        cout << endl;
    }
    printf("\n");
#endif

    mint ans;
    for (int j = 1; j <= n; j++) {
        ans += dp[n][j];
    }
    cout << ans.x << endl;
    return 0;
}
