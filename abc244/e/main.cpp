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

vector<vector<int>> edges;

int main(void) {
    int N, M, K, S, T, X;
    cin >> N >> M >> K >> S >> T >> X;
    S--;
    T--;
    X--;

    edges.resize(2 * N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (u == X) {
            swap(u, v);
        }
        int u_ = u + N;
        int v_ = v + N;

        if (v == X) {
            // top
            edges[v].push_back(u);
            edges[u].push_back(v_);
            // down
            edges[u_].push_back(v);
            edges[v_].push_back(u_);
        } else {
            // top
            edges[u].push_back(v);
            edges[v].push_back(u);
            // down
            edges[u_].push_back(v_);
            edges[v_].push_back(u_);
        }
    }

    vector<mint> dp(2 * N, 0);
    dp[S] = 1;

    for (int k = 0; k < K; k++) {
        vector<mint> tmp_dp(2 * N, 0);
        for (int cur = 0; cur < 2 * N; cur++) {
            for (auto next : edges[cur]) {
                tmp_dp[next] += dp[cur];
            }
        }
        swap(tmp_dp, dp);
    }

    printf("%lld\n", dp[T].x);

    return 0;
}
