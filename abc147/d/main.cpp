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

bool is_all_zero(const vector<ll> &A) {
    for (int i = 0; i < (int) A.size(); i++) {
        if (A[i] != 0) {
            return false;
        }
    }
    return true;
}

ll solve(vector<ll> &A) {
    vector<int> res;
    ll carry = 0;
    while (!is_all_zero(A)) {
        ll count_zero = 0;
        ll count_one = 0;
        for (int i = 0; i < (int) A.size(); i++) {
            if (A[i] % 2 == 0) {
                count_zero++;
            } else {
                count_one++;
            }
            A[i] >>= 1;
        }
        ll acc = count_zero * count_one;
        res.push_back((acc + carry) % 2);
        carry = (acc + carry) / 2;
    }

    while (carry > 0) {
        res.push_back(carry % 2);
        carry >>= 1;
    }

    reverse(res.begin(), res.end());

    // for (int i = 0; i < (int) res.size(); i++) {
    //     cout << res[i] << " ";
    // }
    // cout << endl;

    ll answer = 0;
    for (int i = 0; i < (int) res.size(); i++) {
        answer = (((answer * 2) % MOD) + res[i]) % MOD;
    }
    return answer;
}

int main(void) {
    int N;
    cin >> N;

    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << solve(A) << endl;
    
    return 0;
}
