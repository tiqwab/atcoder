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

ll comb(int n, int k) {
    if (n == 0 || k == 0) {
        return 1;
    }

    ll ans = 1;
    for (int i = 0; i < k; i++) {
        ans *= n;
        n--;
    }
    for (int i = 1; i <= k; i++) {
        ans /= k;
    }
    return ans;
}

vector<vector<ll>> dp1;
vector<vector<ll>> dp2;

int main(void) {
    string S;
    int K;
    cin >> S >> K;
    int len = (int) S.size();
    S = " " + S;

    // require more spaces
    dp1.resize(len + 2, vector<ll>(K + 2, 0));
    dp2.resize(len + 2, vector<ll>(K + 2, 0));

    dp1[0][0] = 1;

    for (int i = 0; i < len; i++) {
        for (int j = 0; j <= K; j++) {
            int next_d = S[i + 1] - '0';

            // dp1
            if (next_d == 0) {
                dp1[i + 1][j] += dp1[i][j];
            } else {
                // set same digit
                dp1[i + 1][j + 1] += dp1[i][j];

                // set 0
                dp2[i + 1][j] += dp1[i][j];

                // otherwise
                for (int d = 1; d < next_d; d++) {
                    dp2[i + 1][j + 1] += dp1[i][j];
                }
            }

            // dp2
            dp2[i + 1][j] += dp2[i][j];
            dp2[i + 1][j + 1] += dp2[i][j] * 9;
        }
    }

    // printf("dp1: \n");
    // for (int i = 0; i <= len; i++) {
    //     for (int j = 0; j <= K; j++) {
    //         cout << dp1[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // printf("dp2: \n");
    // for (int i = 0; i <= len; i++) {
    //     for (int j = 0; j <= K; j++) {
    //         cout << dp2[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    cout << dp1[len][K] + dp2[len][K] << endl;

    return 0;
}
