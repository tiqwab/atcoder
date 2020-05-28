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

const ll MOD = ll(1e9 + 7);

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
vector<int> cs;

// the position of '?'
vector<int> qs;

vector<vector<mint>> dp;

mint solve(const int slen, const string &S) {
    for (int i = 0; i < slen; i++) {
        for (int j = 0; j <= 3; j++) {
            char c = S[i];
            if (c == 'A') {
                dp[i + 1][j] += dp[i][j];
                if (j == 1) {
                    dp[i + 1][j] += dp[i][j - 1];
                }
            } else if (c == 'B') {
                dp[i + 1][j] += dp[i][j];
                if (j == 2) {
                    dp[i + 1][j] += dp[i][j - 1];
                }
            } else if (c == 'C') {
                dp[i + 1][j] += dp[i][j];
                if (j == 3) {
                    dp[i + 1][j] += dp[i][j - 1];
                }
            } else {
                dp[i + 1][j] += dp[i][j] * 3;
                if (j > 0) {
                    dp[i + 1][j] += dp[i][j - 1];
                }
            }
        }
    }

    return dp[slen][3];
}

int main(void) {
    string S;
    cin >> S;
    int slen = (int) S.size();

    for (int i = 0; i < (int) S.size(); i++) {
        char x = S[i];
        if (x == 'A') {
            as.push_back(i);
        } else if (x == 'B') {
            bs.push_back(i);
        } else if (x == 'C') {
            cs.push_back(i);
        } else {
            qs.push_back(i);
        }
    }

#ifdef DEBUG
    cout << "as: ";
    for (auto x : as) {
        cout << x << " ";
    }
    cout << endl;

    cout << "bs: ";
    for (auto x : bs) {
        cout << x << " ";
    }
    cout << endl;

    cout << "cs: ";
    for (auto x : cs) {
        cout << x << " ";
    }
    cout << endl;
#endif

    dp.resize(slen + 1, vector<mint>(4, 0));
    dp[0][0] = 1;

    mint ans = solve(slen, S);
    cout << ans.x << endl;

#ifdef DEBUG
    for (int i = 0; i <= slen; i++) {
        for (int j = 0; j <= 3; j++) {
            cout << dp[i][j].x << " ";
        }
        cout << endl;
    }
#endif

    return 0;
}
