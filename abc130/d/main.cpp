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

vector<ll> a;
vector<ll> s;

ll solve(const ll N, const ll K) {
    ll count = 0;
    for (int i = 1; i <= N; i++) {
        ll border = K + s[i - 1];
        auto p = lower_bound(s.begin() + i, s.end(), border);
        count += s.end() - p;
    }
    return count;
}

int main(void) {
    ll N, K;
    cin >> N >> K;

    a.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    s.resize(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        s[i] = s[i - 1] + a[i];
    }

    cout << solve(N, K) << endl;

    return 0;
}
