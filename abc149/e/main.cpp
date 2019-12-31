#include <algorithm>
#include <cassert>
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

const ll MAX_A = 100000;

ll cond(const ll mid, const ll N, const vector<ll> &A) {
    ll count = 0;

    for (int i = 0; i < N; i++) {
        auto it = lower_bound(A.begin(), A.end(), mid - A[i]);
        count += A.end() - it;
    }

    return count;
}

ll calc_sum(const ll threshold, const ll N, const ll M, const vector<ll> &sums, const vector<ll> &A) {
    ll acc = 0;
    ll acc_pair = 0;

    for (int i = 0; i < N; i++) {
        auto it = lower_bound(A.begin(), A.end(), threshold - A[i]);
        acc += sums[N] - sums[it - A.begin()] + (A[i] * (A.end() - it));
        acc_pair += (A.end() - it);
        // cout << (it - A.begin()) << "," << acc << endl;
    }

    // there are more than one pair whose sum is threshold (like sample2)
    if (acc_pair > M) {
        acc -= threshold * (acc_pair - M);
    }

    return acc;
}

ll solve(const ll N, const ll M, const vector<ll> &A) {
    ll left = 1, right = MAX_A * 2 + 1, mid;

    while (right - left > 1) {
        mid = left + (right - left) / 2;
        if (cond(mid, N, A) < M) {
            right = mid;
        } else {
            left = mid;
        }
    }

    // the threshold of pairs (of sum) to accumulate
    ll threshold = left;
    // cout << "threshold: " << threshold << endl;

    vector<ll> sums(N + 1);
    sums[0] = 0;
    for (int i = 1; i <= N; i++) {
        sums[i] = sums[i - 1] + A[i - 1];
        // printf("sums[%d]: %lld\n", i, sums[i]);
    }
    return calc_sum(threshold, N, M, sums, A);
}

int main(void) {
    ll N, M;
    cin >> N >> M;

    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    cout << solve(N, M, A) << endl;

    return 0;
}
