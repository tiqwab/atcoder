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
int zero_cnt;

ll solve(const int N, const int K) {
    ll ans = -INF;
    if (zero_cnt > 0) {
        ans = 0;
    }

    if (p_cnt + m_cnt < K) {
        /* do nothing */
    } else if (p_cnt + m_cnt ==  K) {
        mint cand = 1;
        for (int i = 0; i < p_cnt; i++) {
            cand *= ps[i];
        }
        for (int i = 0; i < m_cnt; i++) {
            cand *= ms[i];
        }
        if (m_cnt % 2 == 0) {
            ans = cand.x;
        } else {
            if (ans == -INF) {
                ans = cand.x;
            }
        }
    } else if (p_cnt == 0) {
        mint cand = 1;
        sort(ms.begin(), ms.end());
        if (K % 2 != 0) {
            reverse(ms.begin(), ms.end());
        }
        for (int i = 0; i < K; i++) {
            cand *= ms[i];
        }
        if (ans == -INF || K % 2 == 0) {
            ans = cand.x;
        }
    } else {
        // we may use minus values
        sort(ps.begin(), ps.end());
        reverse(ps.begin(), ps.end());

        sort(ms.begin(), ms.end());

        mint cand = 1;

        int pi = 0;
        int mi = 0;
        int cnt = 0;
        while (pi < p_cnt && mi < m_cnt && cnt < K) {
            if (ps[pi] >= abs(ms[mi])) {
                cand *= ps[pi];
                pi++;
            } else {
                cand *= ms[mi];
                mi++;
            }
            cnt++;
        }

        while (pi < p_cnt && cnt < K) {
            cand *= ps[pi];
            cnt++;
            pi++;
        }

        while (mi < m_cnt && cnt < K) {
            cand *= ms[mi];
            cnt++;
            mi++;
        }

        assert(cnt == K);

        if (mi % 2 != 0) {
            ll m_last = (mi > 0) ? ms[mi - 1] : 0;
            ll m_cand = ms[mi];
            ll p_last = (pi > 0) ? ps[pi - 1] : INF;
            ll p_cand = (pi < p_cnt) ? ps[pi] : 0;
            // printf("mi: %d, pi: %d, m_last: %lld, m_cand: %lld, p_first: %lld, p_cand: %lld\n",
            //         mi, pi, m_last, m_cand, p_last, p_cand);

            if (K == 1) {
                cand /= m_last;
                cand *= p_cand;
            } else if (pi == 0) {
                cand /= m_last;
                cand *= p_cand;
            } else {
                if (m_last * m_cand > p_last * p_cand) {
                    cand /= p_last;
                    cand *= m_cand;
                } else {
                    cand /= m_last;
                    cand *= p_cand;
                }
            }
        }

        ans = cand.x;
    }

    return ans;
}

int main(void) {
    int N, K;
    cin >> N >> K;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
        if (as[i] == 0) {
            zero_cnt++;
        } else if (as[i] > 0) {
            ps.push_back(as[i]);
            p_cnt++;
        } else {
            ms.push_back(as[i]);
            m_cnt++;
        }
    }

    // printf("zero_cnt: %d, p_cnt: %d, m_cnt: %d\n", zero_cnt, p_cnt, m_cnt);

    cout << solve(N, K) << endl;

    return 0;
}
