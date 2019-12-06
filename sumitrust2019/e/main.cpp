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

const ll MAX_N = 100000;
const ll MOD = 1000000007;

ll solve(const int n, const vector<ll> &A) {
    int counter[3] = {0, 0, 0};
    ll acc = 1;
    for (int i = 0; i < n; i++) {
        ll a = 0;
        bool found = false;
        ll x = A[i];

        for (int j = 0; j < (int) (sizeof(counter) / sizeof(counter[0])); j++) {
            if (x == counter[j]) {
                if (!found) {
                    counter[j]++;
                    found = true;
                }
                a++;
            }
        }
        acc = (acc * (a % MOD)) % MOD;
    }
    return acc;
}

int main(void) {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << solve(N, A) << endl;
    
    return 0;
}
