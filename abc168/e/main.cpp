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

const int MOD = 1000000007;

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

ll gcd(const ll sx, const ll sy) {
    ll x = min(sx, sy);
    ll y = max(sx, sy);
    ll tmp;
    while (x > 0) {
        tmp = y;
        y = x;
        x = tmp % x;
    }
    return y;
}

vector<ll> as;
vector<ll> bs;

// {bunshi, bunbo}: index
// bunshi always has sign
map<pair<ll, ll>, set<int>> ms;
vector<pair<ll, ll>> ps;

int group_no;
vector<int> groups; // groups[i] means what group iwashi i belongs to
map<int, int> opposite_group; // opposite_group[i] means the opposite group.
map<int, int> group_size; // group_size[i] means the size of group i.

mint solve(const int group_no_pairs, const int group_no_any, const int N) {
    mint ans(1);
    vector<bool> used(group_no_pairs, false);

    for (int i = 0; i < group_no_pairs; i++) {
        if (used[i]) continue;
        mint acc(1);
        acc += mint(2).pow(group_size[i]) - 1;
        acc += mint(2).pow(group_size[opposite_group[i]]) - 1;
        ans *= acc;
        used[i] = true;
        used[opposite_group[i]] = true;
    }

    // group_no_any don't have opposite pair
    ans *= mint(2).pow(group_size[group_no_any]);

    ans -= 1;

    return ans;
}

int main(void) {
    int N;
    cin >> N;

    as.resize(N);
    bs.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i] >> bs[i];
    }

    ps.resize(N);
    for (int i = 0; i < N; i++) {
        ll g = gcd(abs(as[i]), abs(bs[i]));
        if (g == 0) g = 1;
        ll bunshi = as[i] / g;
        ll bunbo = bs[i] / g;
        if (bunbo == 0 && bunshi != 0) {
            bunshi = 1;
        } else if (bunbo != 0 && bunshi == 0) {
            bunbo = 1;
        }
        // if (bunshi * bunbo < 0) { /* overflow... */
        if ((bunshi < 0 && bunbo > 0) || (bunshi > 0 && bunbo < 0)) {
            bunshi = -1 * abs(bunshi);
            bunbo = abs(bunbo);
        }
        // printf("[%d] bunshi: %lld, bunbo: %lld\n", i, bunshi, bunbo);
        ps[i] = {bunshi, bunbo};
        ms[ps[i]].insert(i);
    }

    groups.resize(N, -1);

    for (int i = 0; i < N; i++) {
        ll my_bunshi = ps[i].first;
        ll my_bunbo = ps[i].second;

        ll other_bunshi = my_bunbo;
        ll other_bunbo = my_bunshi;
        if (other_bunbo > 0) {
            // other should be negative
            other_bunshi *= -1;
        } else {
            // other should be positive
            other_bunbo *= -1;
        }

        int other_group = -1;

        if (groups[i] >= 0 || (my_bunshi == 0 && my_bunbo == 0)) {
            continue;
        }

        if (ms.find({other_bunshi, other_bunbo}) == ms.end()) {
            continue;
        }

        // printf("pair for %d: \n", i);
        for (auto &other_ind : ms[{other_bunshi, other_bunbo}]) {
            if (groups[i] < 0 && groups[other_ind] < 0) {
                int my_group = group_no++;
                groups[i] = my_group;
                other_group = group_no++;
                groups[other_ind] = other_group;
                opposite_group[my_group] = other_group;
                opposite_group[other_group] = my_group;
            } else if (groups[i] < 0 && groups[other_ind] >= 0) {
                other_group = groups[other_ind];
                int my_group = opposite_group[other_group];
                groups[i] = my_group;
            } else if (groups[i] >= 0 && groups[other_ind] < 0) {
                int my_group = groups[i];
                other_group = opposite_group[my_group];
                groups[other_ind] = other_group;
            } else {
                // do nothing
            }
            // cout << other_ind << " ";
        }
        // cout << endl;

        if (ms.find({my_bunshi, my_bunbo}) != ms.end()) {
            for (auto &same_ind : ms[{my_bunshi, my_bunbo}]) {
                groups[same_ind] = groups[i];
            }
        }
    }

    int group_no_pairs = group_no - 1;

    int group_no_zero = group_no++;
    opposite_group[group_no_zero] = -1;
    for (int i = 0; i < N; i++) {
        ll my_bunshi = ps[i].first;
        ll my_bunbo = ps[i].second;
        if (my_bunshi == 0 && my_bunbo == 0) {
            groups[i] = group_no_zero;
        }
    }

    int group_no_any = group_no++;
    opposite_group[group_no_any] = -1;
    for (int i = 0; i < N; i++) {
        if (groups[i] < 0) {
            groups[i] = group_no_any;
        }
    }

    for (int i = 0; i < N; i++) {
        group_size[groups[i]]++;
    }

    // check constructed data
    // {
    //     map<int, set<int>> iwashi_per_group;
    //     for (int i = 0; i < N; i++) {
    //         iwashi_per_group[groups[i]].insert(i);
    //     }
    //     for (auto &p : iwashi_per_group) {
    //         printf("group %d: ", p.first);
    //         for (auto &x : p.second) {
    //             cout << x << " ";
    //         }
    //         cout << endl;
    //         printf("  opposite group: %d\n", opposite_group[p.first]);
    //     }
    // }

    mint ans = solve(group_no_pairs, group_no_any, N);
    ans += group_size[group_no_zero];
    cout << ans.x << endl;

    return 0;
}
