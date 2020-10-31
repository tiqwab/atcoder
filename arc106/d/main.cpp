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

vector<mint> as;

vector<mint> bs;

vector<mint> factorial;

vector<mint> sum_diagonal;

int main(void) {
    int N, K;
    cin >> N >> K;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        as[i] = mint(x);
    }

    factorial.resize(K + 1);
    factorial[0] = mint(1);
    {
        mint acc = mint(1);
        for (int i = 1; i <= K; i++) {
            acc *= i;
            factorial[i] = acc;
        }
    }

    bs.resize(K + 1);
    {
        for (int i = 0; i < N; i++) {
            mint base = as[i];
            mint acc = mint(1);
            for (int x = 0; x <= K; x++) {
                bs[x] += acc;
                acc *= base;
            }
        }
    }

#ifdef DEBUG
    printf("bs: \n");
    for (int i = 0; i <= K; i++) {
        printf("%lld\n", bs[i].x);
    }
    printf("\n");
#endif

    sum_diagonal.resize(K + 1);
    {
        for (int i = 0; i < N; i++) {
            mint base = as[i] * 2;
            mint acc = mint(1);
            for (int x = 0; x <= K; x++) {
                sum_diagonal[x] += acc;
                acc *= base;
            }
        }
    }

    {
        for (int x = 1; x <= K; x++) {
            mint acc = mint(0);
            for (int y = 0; y <= x; y++) {
                acc += (bs[y] / factorial[y]) * (bs[x - y] / factorial[x - y]);
            }
            acc *= factorial[x];
            acc -= sum_diagonal[x];
            acc /= 2;
            printf("%lld\n", acc.x);
        }
    }

    return 0;
}
