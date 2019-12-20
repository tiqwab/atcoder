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

ll solve(vector<ll> &A, vector<ll> &B) {
    ll count = 0;

    for (int i = 0; i < (int) B.size(); i++) {
        for (int j = 0; j < 2; j++) {
            if (A[i + j] > 0) {
                int diff = min(A[i + j], B[i]);
                B[i] -= diff;
                A[i + j] -= diff;
                count += diff;
            }
        }
    }

    return count;
}

int main(void) {
    int N;
    cin >> N;

    vector<ll> A(N + 1);
    for (int i = 0;  i < N + 1; i++) {
        cin >> A[i];
    }

    vector<ll> B(N);
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    cout << solve(A, B) << endl;

    return 0;
}
