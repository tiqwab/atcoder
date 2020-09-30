#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
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

ll f(const ll x, const ll m) {
    return ((x % m) * (x % m)) % m;
}

// ref. official YouTube video
int main(void) {
    ll N;
    int X, M;
    cin >> N >> X >> M;

    if (X == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> ord(M, -1);
    vector<int> xs;
    ll total = 0;
    int len = 0;
    ll cur = X;
    while (ord[cur] == -1) {
        ord[cur] = len;
        total += cur;
        xs.push_back(cur);
        cur = (cur * cur) % M;
        len++;
    }

    if (N <= len) {
        ll ans = 0;
        for (int i = 0; i < N; i++) {
            ans += xs[i];
        }
        cout << ans << endl;
        return 0;
    }

    int loop_size = len - ord[cur];
    ll loop_sum = 0;
    for (int i = ord[cur]; i < len; i++) {
        loop_sum += xs[i];
    }

    ll ans = total;
    N -= len;
    ans += (N / loop_size) * loop_sum;
    N %= loop_size;
    for (int i = 0; i < N; i++) {
        ans += xs[i + ord[cur]];
    }

    cout << ans << endl;
    return 0;
}
