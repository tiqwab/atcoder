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

const int INF = INT_MAX / 2;

vector<ll> as;

// plus values
vector<ll> ps;

// minus values
vector<ll> ms;

int p_cnt;
int m_cnt;

ll solve(const int N, const int K) {
    if (N == K) {
        mint ans = 1;
        for (int i = 0; i < K; i++) {
            ans *= as[i];
        }
        return ans.x;
    }

    if (p_cnt == 0) {
        mint ans = 1;
        if (K % 2 != 0) {
            reverse(ms.begin(), ms.end());
        }
        for (int i = 0; i < K; i++) {
            ans *= ms[i];
        }
        return ans.x;
    }

    // the result >= 0
    // p_cnt > 0
    // N > K

    mint ans = 1;
    int pi = 0;
    int mi = 0;
    int cnt = 0;
    if (K % 2 != 0) {
        ans *= ps[pi];
        pi++;
        cnt++;
    }

    priority_queue<ll> pq;
    for (; pi + 2 <= p_cnt; pi += 2) {
        pq.push(ps[pi] * ps[pi + 1]);
    }
    for (; mi + 2 <= m_cnt; mi += 2) {
        pq.push(ms[mi] * ms[mi + 1]);
    }

    while (cnt < K) {
        ll v = pq.top();
        pq.pop();
        ans *= v;
        cnt += 2;
    }

    return ans.x;
}

int main(void) {
    int N, K;
    cin >> N >> K;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
        if (as[i] >= 0) {
            ps.push_back(as[i]);
            p_cnt++;
        } else {
            ms.push_back(as[i]);
            m_cnt++;
        }
    }

    sort(ps.begin(), ps.end());
    reverse(ps.begin(), ps.end());
    sort(ms.begin(), ms.end());

    cout << solve(N, K) << endl;

    return 0;
}
