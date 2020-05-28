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

// acc_bs_cs[0] means the number of possible 'C's from bs[0]
vector<ll> acc_bs_cs;
// acc_bs_as[1] means the number of possible 'A's from bs[0] (indexing is different from acc_bs_cs...)
vector<ll> acc_bs_as;

// the position of '?'
vector<int> qs;

mint solve() {
    mint cnt = 0;

    // (1) not use '?'
    for (auto a : as) {
        auto it_b = upper_bound(bs.begin(), bs.end(), a);
        if (it_b != bs.end()) {
            mint acc = acc_bs_cs[distance(bs.begin(), it_b)];
            acc *= mint(3).pow((int) qs.size());
#ifdef DEBUG
            printf("(1): %lld\n", acc.x);
#endif
            cnt += acc;
        }
    }

    // (2) use '?' for "A"
    for (auto pos : qs) {
        auto it_b = upper_bound(bs.begin(), bs.end(), pos);
        if (it_b != bs.end()) {
            mint acc = acc_bs_cs[distance(bs.begin(), it_b)];
            acc *= mint(3).pow((int) qs.size() - 1);
#ifdef DEBUG
            printf("(2): %lld\n", acc.x);
#endif
            cnt += acc;
        }
    }

    // (3) use '?' for "B"
    for (auto pos : qs) {
        auto it_a = lower_bound(as.begin(), as.end(), pos);
        if (it_a == as.begin()) continue;
        auto it_c = upper_bound(cs.begin(), cs.end(), pos);
        if (it_c == cs.end()) continue;
        mint acc = mint(distance(as.begin(), it_a)) * mint(distance(it_c, cs.end()));
        acc *= mint(3).pow((int) qs.size() - 1);
#ifdef DEBUG
        printf("(3): %lld\n", acc.x);
#endif
        cnt += acc;
    }

    // (4) use '?' for "C"
    for (auto pos_c : qs) {
        auto it_b = lower_bound(bs.begin(), bs.end(), pos_c);
        if (it_b != bs.begin()) {
            mint acc = acc_bs_as[distance(bs.begin(), it_b)];
            acc *= mint(3).pow((int) qs.size() - 1);
#ifdef DEBUG
            printf("(4): %lld\n", acc.x);
#endif
            cnt += acc;
        }
    }

    // (5) use '?' for "AB"
    for (int i = 1; i < (int) qs.size(); i++) {
        int pos_b = qs[i];
        auto it_c = upper_bound(cs.begin(), cs.end(), pos_b);
        if (it_c == cs.end()) continue;
        mint acc = distance(it_c, cs.end());
        acc *= i;
        acc *= mint(3).pow((int) qs.size() - 2);
#ifdef DEBUG
        printf("(5): %lld\n", acc.x);
#endif
        cnt += acc;
    }

    // (6) use '?' for "AC"
    for (auto pos_b : bs) {
        auto it = upper_bound(qs.begin(), qs.end(), pos_b);
        if (it == qs.begin() || it == qs.end()) continue;
        mint acc = mint(distance(qs.begin(), it)) * mint(distance(it, qs.end()));
        acc *= mint(3).pow((int) qs.size() - 2);
#ifdef DEBUG
        printf("(6): %lld\n", acc.x);
#endif
        cnt += acc;
    }

    // (7) use '?' for "BC"
    for (auto pos_a : as) {
        auto it = upper_bound(qs.begin(), qs.end(), pos_a);
        int dist = distance(it, qs.end());
        if (dist < 2) continue;
        mint acc = mint(dist) * mint(dist - 1) / 2;
        acc *= mint(3).pow((int) qs.size() - 2);
#ifdef DEBUG
        printf("(7): %lld\n", acc.x);
#endif
        cnt += acc;
    }

    // (8) use '?' for "ABC"
    if ((int) qs.size() >= 3) {
        mint n = qs.size();
        mint acc = n * (n - 1) * (n - 2) / 6;
        acc *= mint(3).pow((int) qs.size() - 3);
#ifdef DEBUG
        printf("(8): %lld\n", acc.x);
#endif
        cnt += acc;
    }

    return cnt;
}

int main(void) {
    string S;
    cin >> S;

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

    acc_bs_cs.resize((int) bs.size() + 1, 0);
    for (int i = (int) bs.size() - 1; i >= 0; i--) {
        const int b = bs[i];
        auto it_c = upper_bound(cs.begin(), cs.end(), b);
        acc_bs_cs[i] = acc_bs_cs[i + 1];
        acc_bs_cs[i] = (acc_bs_cs[i] + distance(it_c, cs.end())) % MOD;
    }

#ifdef DEBUG
    printf("acc_bs_cs: \n");
    for (int i = 0; i < (int) acc_bs_cs.size(); i++) {
        cout << acc_bs_cs[i] << " ";
    }
    cout << endl;
#endif

    acc_bs_as.resize((int) bs.size() + 1, 0);
    for (int i = 0; i < (int) bs.size(); i++) {
        const int b = bs[i];
        auto it_a = lower_bound(as.begin(), as.end(), b);
        acc_bs_as[i + 1] = acc_bs_as[i];
        acc_bs_as[i + 1] = (acc_bs_as[i + 1] + distance(as.begin(), it_a)) % MOD;
    }

#ifdef DEBUG
    printf("acc_bs_as: \n");
    for (int i = 0; i < (int) acc_bs_as.size(); i++) {
        cout << acc_bs_as[i] << " ";
    }
    cout << endl;
#endif

    mint ans = solve();
    cout << ans.x << endl;

    return 0;
}
