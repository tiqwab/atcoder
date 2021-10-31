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

vector<vector<int>> edges;

map<pair<int, int>, int> edge_to_id;

bool calc_route_for(const int cur, const int prev, const int dst, vector<int> &acc) {
    acc.push_back(cur);

    if (cur == dst) {
        return true;
    }

    for (auto next : edges[cur]) {
        if (next == prev) {
            continue;
        }
        if (calc_route_for(next, cur, dst, acc)) {
            return true;
        }
    }

    acc.pop_back();

    return false;
}

mint solve(const vector<int> &path_useds, const int path_sum, const int K) {
    const int MAX_SUM = 1000 * 100;

    vector<mint> dp;

    dp.resize(MAX_SUM + 1, 0);
    dp[0] = 1;

    for (auto path_used : path_useds) {
        for (int i = MAX_SUM - path_used; i >= 0; i--) {
            const int to = i + path_used;
            dp[to] += dp[i];
        }
    }

    mint ans = 0;

    for (int i = 0; i <= MAX_SUM; i++) {
        if (path_sum - i == K + i) {
            ans += dp[i];
        }
    }

    return ans;
}

int main(void) {
    int N, M, K;
    cin >> N >> M >> K;

    if (K < 0) {
        K *= -1;
    }

    as.resize(M);
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        a--;
        as[i] = a;
    }

    edges.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
        edge_to_id[make_pair(u, v)] = i;
        edge_to_id[make_pair(v, u)] = i;
    }

    vector<int> path_used(N - 1, 0);

    for (int i = 0; i < M - 1; i++) {
        vector<int> route;
        calc_route_for(as[i], -1, as[i + 1], route);
#ifdef DEBUG
        printf("from %d to %d: ", as[i], as[i + 1]);
        for (auto x : route) {
            printf("%d ", x);
        }
        printf("\n");
#endif
        for (int j = 0; j < (int) route.size() - 1; j++) {
            path_used[edge_to_id[make_pair(route[j], route[j + 1])]] += 1;
        }
    }

    int path_used_sum = 0;

    for (int i = 0; i < N - 1; i++) {
        path_used_sum += path_used[i];
    }

    cout << solve(path_used, path_used_sum, K).x << endl;

    return 0;
}
