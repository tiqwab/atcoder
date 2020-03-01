#include <algorithm>
#include <cmath>
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

vector<int> A;
vector<int> L;
vector<int> R;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// based on pdf
// https://img.atcoder.jp/abc125/editorial.pdf
int main(void) {
    int N;
    cin >> N;

    A.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    L.resize(N + 1, 0);
    L[1] = A[1];
    for (int i = 2; i <= N; i++) {
        L[i] = gcd(max(L[i - 1], A[i]), min(L[i - 1], A[i]));
    }

    R.resize(N + 1, 0);
    R[1] = A[N];
    for (int i = 2; i <= N; i++) {
        R[i] = gcd(max(R[i - 1], A[N - i + 1]), min(R[i - 1], A[N - i + 1]));
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        chmax(ans, gcd(max(L[i - 1], R[N - i]), min(L[i - 1], R[N - i])));
    }

    cout << ans << endl;

    return 0;
}
