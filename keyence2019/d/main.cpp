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

const ll MOD = 1000000007LL;
const ll INF = LONG_LONG_MAX / 2LL;

vector<ll> A;
vector<ll> B;

ll count_same(const ll value, const vector<ll> &xs) {
    auto l = lower_bound(xs.begin(), xs.end(), value);
    auto u = upper_bound(xs.begin(), xs.end(), value);
    return u - l;
}

ll count_same_or_larger(const ll value, const vector<ll> &xs) {
    auto l = lower_bound(xs.begin(), xs.end(), value);
    return xs.end() - l;
}

int main(void) {
    int N, M;
    cin >> N >> M;

    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    B.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }
    sort(B.begin(), B.end());

    ll acc = 1;
    const ll K = N * M;
    for (int i = K; i >= 1; i--) {
        ll count_same_A = count_same(i, A);
        ll count_same_B = count_same(i, B);
        ll count_sl_A = count_same_or_larger(i, A);
        ll count_sl_B = count_same_or_larger(i, B);

        if (count_same_A > 1 || count_same_B > 1) {
            cout << "0" << endl;
            return 0;
        } else if (count_same_A == 1 && count_same_B == 1) {
            // there is only one possiblity
        } else if (count_same_A == 1) {
            acc = acc * count_sl_B % MOD;
        } else if (count_same_B == 1) {
            acc = acc * count_sl_A % MOD;
        } else {
            acc = acc * ((count_sl_A * count_sl_B - (K - i)) % MOD) % MOD;
        }
    }

    cout << acc << endl;

    return 0;
}
