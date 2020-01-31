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

vector<bool> stairs; // ok if true
vector<ll> dp;

void solve(const int N) {
    for (int i = 1; i <= N; i++) {
        if (!stairs[i]) continue;
        if (i >= 1 && stairs[i - 1]) {
            dp[i] = (dp[i] + dp[i -1]) % MOD;
        }
        if (i >= 2 && stairs[i - 2]) {
            dp[i] = (dp[i] + dp[i - 2]) % MOD;
        }
    }
}

int main(void) {
    int N, M;
    cin >> N >> M;

    stairs.resize(N + 1, true);
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        stairs[a] = false;
    }

    dp.resize(N + 1);
    dp[0] = 1;

    solve(N);

    cout << dp[N] << endl;

    return 0;
}
