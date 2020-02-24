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

vector<ll> A;
vector<ll> S;
map<ll, ll> counter;

int main(void) {
    ll N, M;
    cin >> N >> M;

    A.resize(N + 1, 0);
    S.resize(N + 1, 0);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        A[i + 1] = x;
        S[i + 1] = S[i] + x;
    }

    ll acc = 0;
    for (int i = 0; i <= N; i++) {
        ll x = S[i] % M;
        acc += counter[x];
        counter[x]++;
    }

    cout << acc << endl;

    return 0;
}
