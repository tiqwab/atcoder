#include <algorithm>
#include <iostream>
#include <vector>

#include <limits.h>
#include <math.h>

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

void list_candidate(const int N, const vector<int> &A, vector<int> &cands) {
    int sum = 0;
    for (int i = 0; i < (int) A.size(); i++) {
        sum += A[i];
    }

    cands.push_back(1);
    cands.push_back(sum);
    for (int i = 2; i <= (int) sqrt(sum); i++) {
        if (sum % i == 0) {
            cands.push_back(i);
            cands.push_back(sum / i);
        }
    }
    // descending order
    sort(cands.begin(), cands.end(), [](const int &a, const int &b) {
            return a > b;
            });
}

bool try_division(const int N, const int K, const vector<int> &A, const int cand) {
    // cout << "try_division: " << cand << endl;

    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        B[i] = A[i] % cand;
    }
    sort(B.begin(), B.end());

    vector<ll> acc_minus(N);
    acc_minus[0] = B[0];
    for (int i = 1; i < N; i++) {
        acc_minus[i] = acc_minus[i - 1] + B[i];
    }

    // for (int i = 0; i < N; i++) {
    //     cout << acc_minus[i] << " ";
    // }
    // cout << endl;

    vector<ll> acc_plus(N);
    acc_plus[N - 1] = cand - B[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        acc_plus[i] = acc_plus[i + 1] + (cand - B[i]);
    }

    // for (int i = 0; i < N; i++) {
    //     cout << acc_plus[i] << " ";
    // }
    // cout << endl;

    ll min = LONG_LONG_MAX / 2;
    for (int i = 0; i < N - 1; i++) {
        chmin(min, max(acc_minus[i], acc_plus[i + 1]));
        // if (acc_minus[i] == acc_plus[i + 1]) {
        //     if (min > acc_minus[i]) {
        //         min = acc_minus[i];
        //     }
        // }
    }

    return min <= K;
}

int main(void) {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> cands;
    list_candidate(N, A, cands);
    // for (int i = 0; i < (int) cands.size(); i++) {
    //     cout << cands[i] << endl;
    // }

    for (int i = 0; i < (int) cands.size(); i++) {
        if (try_division(N, K, A, cands[i])) {
            cout << cands[i] << endl;
            break;
        }
    }
    
    return 0;
}
