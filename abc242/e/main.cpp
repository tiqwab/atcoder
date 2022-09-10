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

ll solve(const string &S) {
    const int slen = (int) S.size();
    mint acc = 0;

    for (int i = 0; i < slen / 2; i++)  {
        const char c = S[i];
        for (int j = 0; j < (c - 'A'); j++) {
            // (slen / 2) - i - 1 文字は自由に使える
            mint pats = mint(26).pow((slen / 2) - i - 1);

            // 奇数長の場合センターの文字も自由に使える
            if (slen % 2 != 0) {
                pats *= 26;
            }

            acc += pats;
        }
    }

    // 奇数長の場合、センターの文字の考慮がいる
    if (slen % 2 != 0) {
        acc += S[slen / 2] - 'A';
    }

    // 半分一致するものが候補になるか
    {
        string s1 = S.substr(0, slen / 2);
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        string s3;
        if (slen % 2 != 0) {
            s3 = s1 + S[slen / 2] + s2;
        } else {
            s3 = s1 + s2;
        }
        // printf("%s\n", s3.c_str());
        if (s3.compare(S) <= 0) {
            acc += 1;
        }
    }

    return acc.x;
}

int main(void) {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N;
        string S;
        cin >> N >> S;
        printf("%lld\n", solve(S));
    }
    return 0;
}
