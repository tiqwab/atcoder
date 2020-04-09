#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
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

const int MAX_DIGITS = 11;

vector<vector<ll>> dp;

void prepare() {
    for (int i = 1; i < MAX_DIGITS; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == 1) {
                dp[i][j] = 1;
            } else {
                if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j + 1];
                } else if (j == 9) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1];
                }
            }
        }
    }
}

// {d, remai}
tuple<int, int> f(const int cur_pos, const int digit, const int border) {
    ll acc = 0;
    vector<int> xs = {digit - 1, digit, digit + 1};

    for (auto &x : xs) {
        if (x < 0 || x > 9) continue;
        acc += dp[cur_pos - 1][x];
        // printf("x: %d, acc: %lld\n", x, acc);
        if (acc >= border) {
            // return tuple<int, int>(x, acc - border);
            return tuple<int, int>(x, border - (acc - dp[cur_pos - 1][x]));
        }
    }

    return tuple<int, int>(-1, -1);
}

// {digits, d, remain}
tuple<int, int, int> calc_digits(const ll K) {
    ll sum = 0;
    for (int i = 1; i < MAX_DIGITS; i++) {
        for (int j = 1; j < 10; j++) {
            sum += dp[i][j];
        }
    }
    // printf("total_sum: %lld\n", sum);

    int digits;
    int d;
    for (digits = MAX_DIGITS - 1; digits >= 0; digits--) {
        bool ok = false;
        for (d = 9; d >= 1; d--) {
            sum -= dp[digits][d];
            if (sum < K) {
                ok = true;
                break;
            }
        }
        if (ok) {
            break;
        }
    }

    int remain = K - sum;

    return tie(digits, d, remain);
}

ll solve(const ll K) {
    vector<int> ans;

    int digits, d, remain;
    tie(digits, d, remain) = calc_digits(K);
    ans.push_back(d);
    // printf("first_pos: %d, first_digit: %d, first_remain: %d\n", digits, d, remain);

    for (int i = digits; i >= 2; i--) {
        tie(d, remain) = f(i, d, remain);
        // printf("cur_pos: %d, digit: %d, remain: %d\n", i, d, remain);
        assert(d != -1);
        ans.push_back(d);
    }

    ll v = 0;
    for (auto &x : ans) {
        v = v * 10 + x;
    }

    return v;
}

// ll solve(const ll K) {
//     ll sum = 0;
//     for (int i = 1; i < MAX_DIGITS; i++) {
//         for (int j = 1; j < 10; j++) {
//             sum += dp[i][j];
//         }
//     }
//     printf("total_sum: %lld\n", sum);
// 
//     vector<int> ans;
//     ll target = K;
//     int cur_digits = MAX_DIGITS - 1;
//     int digits;
//     int d;
//     while (true) {
//         for (digits = cur_digits; digits >= 0; digits--) {
//             bool ok = false;
//             for (d = 9; d >= 1; d--) {
//                 sum -= dp[digits][d];
//                 if (sum < target) {
//                     ok = true;
//                     break;
//                 }
//             }
//             if (ok) {
//                 break;
//             }
//         }
//         ans.push_back(d);
//         cur_digits = digits - 1;
//         sum = target - sum + dp[digits][d];
//         target = target - sum;
//         printf("sum: %lld, target: %lld\n", sum, target);
//         printf("digits: %d, d: %d\n", digits, d);
//         if (cur_digits <= 0) break;
//     }
// 
//     ll v = 0;
//     for (auto x : ans) {
//         v = v * 10 + x;
//     }
// 
//     return v;
// }

int main(void) {
    ll K;
    cin >> K;

    dp.resize(MAX_DIGITS, vector<ll>(10, 0));
    prepare();

    // for (int i = 0; i < MAX_DIGITS; i++) {
    //     for (int j = 0; j < 10; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    cout << solve(K) << endl;

    return 0;
}
