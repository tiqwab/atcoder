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

int main(void) {
    string S;
    cin >> S;

    if (S == "1") {
        cout << "3" << endl;
        return 0;
    }

    int len = (int) S.size();
    reverse(S.begin(), S.end());
    // bool is_least_zero = S[0] == '0';

    ll for_zero = 1;
    ll for_one = 2;
    ll acc = 0;
    for (int i = 1; i < len; i++) {
        if (S[i - 1] == '0') {
            // for_zero = (for_zero * 2) % MOD;
            // for_one = (for_one * 2) % MOD;
        } else {
            for_zero = (for_zero * 3) % MOD;
            for_one = (for_one * 3) % MOD;
        }
    }
    acc = (for_zero + for_one) % MOD;

    cout << acc << endl;

    return 0;
}
