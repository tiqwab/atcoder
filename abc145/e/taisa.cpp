#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
constexpr ll INF = (1LL << 30) - 1LL;
constexpr ll LINF = (1LL << 60) - 1LL;
constexpr ll MOD = 1e9 + 7;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, t;
    cin >> n >> t;
    vector<P> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    // sort(all(v));
    vector<vector<ll>> dp(n + 1, vector<ll>(t + 3010, -LINF));
    dp[0][0] = 0;
    ll res = 0;

    // Add (i+1)'s v (i in 0-index) if requires
    for (int i = 0; i < n; i++) {
        ll a = v[i].first, b = v[i].second;
        // Note that the above limit is (t + a)
        for (int j = 0; j < t + a; j++) {
            if (j >= a) {
                chmax(dp[i + 1][j], dp[i][j - a] + b);
            }
            chmax(dp[i + 1][j], dp[i][j]);
            chmax(res, dp[i + 1][j]);
            cout << "i: " << i + 1 << ", " << "j: " << j << ", " << dp[i + 1][j] << endl;
        }
    }
    cout << res << endl;
}
