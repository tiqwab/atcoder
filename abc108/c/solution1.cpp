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

int main(void) {
    int N, K;
    cin >> N >> K;

    ll ans = 0;

    for (int i = 0; i < K; i++) {
        if ((i * 2) % K != 0) {
            continue;
        }

        ll acc = 0;

        // TODO: how to calculate a
        ll a = N / K;
        if (i != 0 && i <= N % K) {
            a++;
        }

        acc = a * a;

        ll b = N / K;
        if (K - i != 0 && K - i <= N % K) {
            b++;
        }

        acc *= b;

        // printf("i: %d, a: %lld, b: %lld, acc: %lld\n", i, a, b, acc);

        ans += acc;
    }

    cout << ans << endl;

    return 0;
}
