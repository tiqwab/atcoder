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

vector<int> convert_digits(ll x) {
    vector<int> res;
    while (x > 0) {
        res.push_back(x % 10);
        x /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

void print_digits(const vector<int> xs) {
    for (auto &x : xs) {
        cout << x << " ";
    }
    cout << endl;
}

int calc_used(int x) {
    int used = 0;
    while (x > 0) {
        if (x & 0x1) used++;
        x >>= 1;
    }
    return used;
}

const ll INF = LONG_LONG_MAX / 2;
vector<vector<ll>> dp1; // equal
vector<vector<ll>> dp2; // smalller
vector<vector<ll>> dp3; // bigger

void solve(const vector<int> &digits_A, const ll A, const int K) {
    for (int i = 0; i < (int) digits_A.size(); i++) {
        int digit = digits_A[i];

        // dp1
        for (int j = 0; j < (1 << 10); j++) {
            if (dp1[i][j] == INF) continue;
            for (int k = 0; k < 10; k++) {
                int next_j = j | (1 << k);
                int used = calc_used(next_j);
                if (j == 1) {
                    next_j &= ~0x1;
                    used--;
                }
                if (used > K) continue;

                if (k == digit) {
                    // printf("[dp1] i: %d, j: 0x%x, k: %d, next_j: 0x%x, %lld\n", i, j, k, next_j, dp1[i][j] * 10);
                    dp1[i + 1][next_j] = dp1[i][j] * 10;
                } else if (k < digit) {
                    // to smaller
                    // printf("[dp1 -> dp2] i: %d, j: 0x%x, k: %d, next_j: 0x%x, %d\n", i, j, k, next_j, digit - k);
                    chmin(dp2[i + 1][next_j], dp1[i][j] * 10 + (digit - k));
                } else {
                    // to bigger
                    // printf("[dp1 -> dp3] i: %d, j: 0x%x, k: %d, next_j: 0x%x, %d\n", i, j, k, next_j, k - digit);
                    chmin(dp3[i + 1][next_j], (ll) k - digit);
                }
            }
        }

        // dp2
        for (int j = 0; j < (1 << 10); j++) {
            if (dp2[i][j] == INF) continue;
            for (int k = 0; k < 10; k++) {
                int next_j = j | (1 << k);
                if (j == 1 && next_j != 1) {
                    next_j &= ~0x1;
                } else if (j != next_j) {
                    continue;
                }
                // printf("[dp2] i: %d, j: 0x%x, k: %d, next_j: 0x%x, %lld\n", i, j, k, next_j, dp2[i][j] * 10 + digit - k);
                chmin(dp2[i + 1][next_j], dp2[i][j] * 10 + digit - k);
            }
        }

        // dp3
        for (int j = 0; j < (1 << 10); j++) {
            if (dp3[i][j] == INF) continue;
            for (int k = 0; k < 10; k++) {
                int next_j = j | (1 << k);
                if (j == 1 && next_j != 1) {
                    next_j &= ~0x1;
                } else if (j != next_j) {
                    continue;
                }
                // printf("[dp3] i: %d, j: 0x%x, k: %d, next_j: 0x%x, %lld\n", i, j, k, next_j, dp3[i][j] * 10 + k - digit);
                chmin(dp3[i + 1][next_j], dp3[i][j] * 10 + k - digit);
            }
        }
    }
}

int main(void) {
    ll A;
    int K;
    cin >> A >> K;

    vector<int> digits_A = convert_digits(A);
    int digits_len = (int) digits_A.size();
    // print_digits(digits_A);

    dp1.resize(digits_len + 1, vector<ll>(1 << 10, INF));
    dp2.resize(digits_len + 1, vector<ll>(1 << 10, INF));
    dp3.resize(digits_len + 1, vector<ll>(1 << 10, INF));
    dp1[0][0] = 0;

    solve(digits_A, A, K);

    ll ans = INF;
    for (int i = 0; i < 1 << 10; i++) {
        int used = calc_used(i);
        if (used > K) continue;
        chmin(ans, dp1[digits_len][i]);
        chmin(ans, dp2[digits_len][i]);
        chmin(ans, dp3[digits_len][i]);
    }
    cout << ans << endl;

    return 0;
}
