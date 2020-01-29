#include <algorithm>
#include <iostream>
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

const ll INF = LONG_LONG_MAX / 2;

vector<vector<ll>> dp;
vector<ll> A;
vector<ll> B;

ll solve(int i, int j, const int H, const int N) {
    if (dp[i][j] >= 0) {
        return dp[i][j];
    }

    ll ans = solve(i - 1, j, H, N);
    chmin(ans, solve(i, max(0LL, j - A[i]), H, N) + B[i]);
    dp[i][j] = ans;
    return ans;
}

int main(void) {
    int H, N;
    cin >> H >> N;

    A.resize(N + 1);
    B.resize(N + 1);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        A[i + 1] = a;
        B[i + 1] = b;
    }

    dp.resize(N + 1, vector<ll>(H + 1, -1));
    for (int i = 0; i <= H; i++) {
        dp[0][i] = INF;
    }
    for (int i = 0; i <= N; i++) {
        dp[i][0] = 0;
    }

    solve(N, H, H, N);

    cout << dp[N][H] << endl;
    
    return 0;
}
