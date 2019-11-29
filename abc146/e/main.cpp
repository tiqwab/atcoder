#include <algorithm>
#include <iostream>
#include <map>
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

int main(void) {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }

    vector<ll> B(N + 1, 0);
    for (int i = 0; i < N; i++) {
        B[i + 1] = B[i] + A[i];
    }
    for (int i = 0; i <= N; i++) {
        B[i] = B[i] % K;
    }

    ll answer = 0;
    map<int, ll> m;
    for (int i = 0; i <= N; i++) {
        answer += m[B[i]];
        // cout << answer << endl;
        m[B[i]]++;
        if (i + 1 >= K) {
            m[B[i + 1 - K]]--;
        }
    }

    cout << answer << endl;
    
    return 0;
}
