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

vector<vector<ll>> edges;

bool check(const vector<int> &acc, const int N, const ll K) {
#ifdef DEBUG
    printf("acc: \n");
    for (auto x : acc) {
        cout << x << " ";
    }
    cout << endl;
#endif

    ll dist = 0;
    for (int i = 0; i < N - 1; i++) {
        dist += edges[acc[i]][acc[i + 1]];
    }
    dist += edges[acc[N - 1]][0];
    return dist == K;
}

int solve(set<int> &rem, vector<int> &acc, const int N, const ll K) {
    if ((int) acc.size() == N) {
        if (check(acc, N, K)) {
            return 1;
        } else {
            return 0;
        }
    }

    if ((int) rem.size() == 0) {
        return 0;
    }

    int ans = 0;

    for (auto i : rem) {
        acc.push_back(i);
        set<int> new_rem = rem;
        new_rem.erase(i);
        ans += solve(new_rem, acc, N, K);
        acc.pop_back();
    }

    return ans;
}

int main(void) {
    int N;
    ll K;
    cin >> N >> K;

    edges.resize(N);
    for (int i = 0; i < N; i++) {
        edges[i].resize(N);
        for (int j = 0; j < N; j++) {
            ll t;
            cin >> t;
            edges[i][j] = t;
        }
    }

    vector<int> acc;
    set<int> rem;
    for (int i = 0; i < N; i++) {
        rem.insert(i);
    }
    acc.push_back(0);
    rem.erase(0);

    int ans = solve(rem, acc, N, K);
    cout << ans << endl;
    return 0;
}
