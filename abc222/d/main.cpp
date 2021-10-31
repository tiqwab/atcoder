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

vector<int> as;
vector<int> bs;

int main(void) {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        as.push_back(x);
    }

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        bs.push_back(x);
    }

    vector<mint> dist(3001, 0);
    for (int i = as[0]; i <= bs[0]; i++) {
        dist[i] = 1;
    }
    for (int i = 0; i < N - 1; i++) {
        vector<mint> tmp(3001, 0);

        const int a = as[i];
        const int b = bs[i];
        const int next_a = as[i + 1];
        const int next_b = bs[i + 1];
        for (int j = a; j <= b; j++) {
            int x = max(j, next_a);
            if (x <= next_b) {
                tmp[x] += dist[j];
            }
        }
        for (int j = next_a; j < next_b; j++) {
            tmp[j + 1] += tmp[j];
        }
        swap(dist, tmp);
    }

    mint ans = 0;
    for (auto x : dist) {
        ans += x.x;
    }
    cout << ans.x << endl;

    return 0;
}
