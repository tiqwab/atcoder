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

vector<ll> dp1, dp2;

int main(void) {
    string S;
    cin >> S;

    int slen = (int) S.size();
    dp1.resize(slen, 0);
    dp2.resize(slen, 0);

    // The first digit must be 0
    dp1[0] = 1;
    dp2[0] = 2;

    for (int i = 1; i < slen; i++) {
        if (S[i] == '0') {
            dp1[i] = (dp1[i - 1] * 3) % MOD; // possible bit pairs for (A, B):  (0, 0), (1, 0), (0, 1)
            dp2[i] = dp2[i - 1]; // possible bit pairs for (A, B): (0, 0)
        } else {
            dp1[i] = (((dp1[i - 1] * 3) % MOD) + dp2[i - 1]) % MOD;
            dp2[i] = (dp2[i - 1] * 2) % MOD; // possible bit pairs for (A, B) = (0, 1), (1, 0)
        }
        // printf("dp1[%d]: %lld, dp2[%d]: %lld\n", i, dp1[i], i, dp2[i]);
    }

    cout << (dp1[slen - 1] + dp2[slen - 1]) % MOD << endl;

    return 0;
}
