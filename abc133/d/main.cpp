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

void solve(const int N, const vector<ll> A, vector<ll> &ms) {
    {
        int i = 0;
        ll sign = -1;
        ll v = A[i];
        int cur;
        for (int j = 1; j <= N - 2; j++) {
            cur = (i + j) % N;
            v = v + sign * A[cur];
            sign *= -1;
        }
        // cout << i << "," << v << "," << cur << "," << A[(cur + 1) % N] << endl;
        ms[i] = (v + A[(cur + 1) % N]) / 2;
    }

    for (int i = 1; i < N; i++) {
        ms[i] = A[i - 1] - ms[i - 1];
    }
}

int main(void) {
    int N;
    cin >> N;

    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i] *= 2;
    }

    vector<ll> ms(N);
    solve(N, A, ms);

    cout << ms[0];
    for (int i = 1; i < N; i++) {
        cout << " " << ms[i];
    }
    cout << endl;

    return 0;
}
