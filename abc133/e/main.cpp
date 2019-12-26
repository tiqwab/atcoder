#include <algorithm>
#include <iostream>
#include <vector>

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

const ll MOD = 1000000007;

ll solve(const int N, const int K, const vector<vector<int> > &edges, int cur, int prev) {
    ll acc = 1;
    if (prev == -1) {
        for (int i = 0; i < (int) edges[cur].size() + 1; i++) {
            acc = (acc * (K - i)) % MOD;
        }
    } else {
        for (int i = 0; i < (int) edges[cur].size() - 1; i++) {
            acc = (acc * (K - 2 - i)) % MOD;
        }
    }
    for (int i = 0; i < (int) edges[cur].size(); i++) {
        if (edges[cur][i] == prev) continue;
        acc = (acc * solve(N, K, edges, edges[cur][i], cur)) % MOD;
    }
    return acc;
}

int main(void) {
    int N, K;
    cin >> N >> K;

    vector<vector<int> > edges(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }

    int start;
    int max_edges = 0;
    for (int i = 0; i < N; i++) {
        if (max_edges < (int) edges[i].size()) {
            max_edges = (int) edges[i].size();
            start = i;
        }
    }

    ll ans = solve(N, K, edges, start, -1);
    cout << ans << endl;

    return 0;
}
