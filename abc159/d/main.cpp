#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
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

// {value, count}
map<int, int> m;

ll comb2(const ll n) {
    if (n <= 1) return 0;
    return (n * (n - 1)) / 2;
}

int main(void) {
    int N;
    cin >> N;

    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        m[A[i]]++;
    }

    ll sum = 0;
    for (auto &p : m) {
        ll cnt = p.second;
        sum = sum + comb2(cnt);
    }

    for (int i = 0; i < N; i++) {
        ll x = A[i];
        ll cnt = m[x];
        ll ans = sum - comb2(cnt) + comb2(cnt - 1);
        cout << ans << endl;
    }

    return 0;
}
