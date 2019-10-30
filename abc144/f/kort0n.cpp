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

vector<int> paths[650];
long double dp[650];
int N, M;
long double ans;

void input() {
    cin >> N >> M;
    for(int i = 1; i <= M; i++) {
        int s, t;
        cin >> s >> t;
        paths[s].push_back(t);
    }
}

void f(int block) {
    dp[N] = 0;
    for(int i = N - 1; i >= 1; i--) {
        long double sum = 0.0;
        long double maxi = 0.0;
        int num = paths[i].size();
        for(auto to : paths[i]) {
            sum += dp[to];
            chmax(maxi, dp[to]);
        }
        if(i == block && num >= 2) {
            num--;
            sum -= maxi;
        }
        dp[i] = sum / num + 1;
    }
    chmin(ans, dp[1]);
}

void solve() {
    input();
    ans = 1e18;
    for(int i = 0; i <= N - 1; i++) {
        f(i);
    }
    cout << fixed << setprecision(10) << ans << endl;
    return;
}

int main() {
    solve();
    return 0;
}
