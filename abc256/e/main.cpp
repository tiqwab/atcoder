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

int dfs(const int cur, const vector<int> &to, const vector<ll> &complain, const vector<bool> &visited, set<int> &acc) {
    if (visited[cur]) {
        return -1;
    }

    if (acc.find(cur) != acc.end()) {
        return cur;
    }
    acc.insert(cur);

    const int next = to[cur];
    int v = dfs(next, to, complain, visited, acc);
    if (v >= 0) {
        return v;
    }

    return -1;
}

ll calc_minimum_complain_from_loop(const int start, const vector<int> &to, const vector<ll> &complain) {
    ll min_complain = complain[start];
    int cur = to[start];
    while (cur != start) {
        chmin(min_complain, complain[cur]);
        cur = to[cur];
    }
    return min_complain;
}

int main(void) {
    int N;
    cin >> N;

    vector<int> to(N);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        x--;
        to[i] = x;
    }

    vector<ll> complain(N);
    for (int i = 0; i < N; i++) {
        int c;
        cin >> c;
        complain[i] = c;
    }

    vector<bool> visited(N, false);
    ll ans = 0;

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            set<int> acc;
            int v = dfs(i, to, complain, visited, acc);
            if (v >= 0) {
                // loop detected
#ifdef DEBUG
                printf("loop containing %d detected\n", v);
#endif
                ans += calc_minimum_complain_from_loop(v, to, complain);
#ifdef DEBUG
                printf("ans: %lld\n", ans);
#endif
            }
            for (auto v : acc) {
                visited[v] = true;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
