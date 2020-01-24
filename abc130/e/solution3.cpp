#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

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

vector<ll> S;
vector<ll> T;

// dp[i][j] means the number of patterns for S[0..(i-1)] containing S[i-1] and T[0..(j-1)] containing T[j-1]
mint dp[2005][2005];
mint sdp[2005][2005];

// ref. solution2 of http://drken1215.hatenablog.com/entry/2019/06/21/230200
int main(void) {
    ll N, M;
    cin >> N >> M;

    S.resize(N + 1, 0);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    T.resize(M + 1, 0);
    for (int i = 0; i < M; i++) {
        cin >> T[i];
    }

    dp[0][0] = 1;
    for (int i = 0; i <= N; i++) sdp[i][0] = 1;
    for (int i = 0; i <= M; i++) sdp[0][i] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            sdp[i][j] = sdp[i - 1][j] + sdp[i][j - 1] - sdp[i - 1][j - 1];
            if (S[i - 1] == T[j - 1]) {
                dp[i][j] = sdp[i - 1][j -1];
                sdp[i][j] += dp[i][j];
            }
        }
    }

    // mint ans = 0;
    // for (int i = 0; i < N + 1; i++) {
    //     for (int j = 0; j < M + 1; j++) {
    //         printf("%lld ", dp[i][j].x);
    //         ans += dp[i][j];
    //     }
    //     printf("\n");
    // }

    // for (int i = 0; i < N + 1; i++) {
    //     for (int j = 0; j < M + 1; j++) {
    //         printf("%lld ", sdp[i][j].x);
    //     }
    //     printf("\n");
    // }

    cout << sdp[N][M].x << endl;

    return 0;
}
