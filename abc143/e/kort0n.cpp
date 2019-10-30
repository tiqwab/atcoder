#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
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

const ll INF = 1e17;
ll N, M, L, Q;
ll fuel[305][305];
ll dist[305][305];
ll s[105000], t[105000];
ll A[100000], B[100000], C[100000];

void input() {
    cin >> N >> M >> L;
    for(int i = 1; i <= M; i++) cin >> A[i] >> B[i] >> C[i];
    cin >> Q;
    for(int i = 1; i <= Q; i++) cin >> s[i] >> t[i];
}

void solve() {
    input();
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            fuel[i][j] = INF;
            dist[i][j] = INF;
        }
        fuel[i][i] = 0;
        dist[i][i] = 0;
    }
    for(int i = 1; i <= M; i++) {
        chmin(fuel[A[i]][B[i]], C[i]);
        chmin(fuel[B[i]][A[i]], C[i]);
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= N; k++) {
                chmin(fuel[j][k], fuel[j][i] + fuel[i][k]);
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i == j) continue;
            if(fuel[i][j] <= L) chmin(dist[i][j], 1LL);
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= N; k++) {
                chmin(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
    for(int i = 1; i <= Q; i++) {
        if(dist[t[i]][s[i]] < INF) cout << dist[t[i]][s[i]] - 1 << "\n";
        else cout << -1 << "\n";
    }
    return;
}

int main() {
    solve();
    return 0;
}
