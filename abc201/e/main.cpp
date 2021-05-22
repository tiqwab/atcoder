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

const ll MOD = 1000000007LL;

// {to, weight}
vector<vector<pair<int, ll>>> edges;

vector<ll> calculated;

void calculate(const int cur_v, const ll cur_w, const int N) {
    if (calculated[cur_v] != -1) {
        return;
    }

    calculated[cur_v] = cur_w;

    for (auto edge : edges[cur_v]) {
        calculate(edge.first, cur_w ^ edge.second, N);
    }
}

int main(void) {
    int N;
    cin >> N;

    edges.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--;
        v--;
        edges[u].push_back(make_pair(v, w));
        edges[v].push_back(make_pair(u, w));
    }

    calculated.resize(N, -1);
    calculate(0, 0, N);

#ifdef DEBUG
    printf("calculated: \n");
    for (auto w : calculated) {
        cout << w << endl;
    }
    cout << endl;
#endif

    ll ans = 0;
    for (int i = 0; i < 60; i++) {
        const ll power = 1L << i;
        ll zero_cnt = 0;
        ll one_cnt = 0;
        for (int i = 0; i < N; i++) {
            if (calculated[i] & power) {
                one_cnt++;
            } else {
                zero_cnt++;
            }
        }
        const ll cnt = zero_cnt * one_cnt;
        ans = (ans + (cnt % MOD) * (power % MOD)) % MOD;
    }

    cout << ans << endl;

    return 0;
}
