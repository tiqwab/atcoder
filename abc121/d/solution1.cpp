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

// 2^60 > 10 ^ 12
const int MAX_BITS = 60;

vector<int> bits(60, 0);

ll count(const ll x, const ll base) {
    ll cnt = 0;
    cnt += (x / base) * (base / 2LL);
    cnt += max(0LL, (x % base) - (base / 2LL - 1));
    return cnt;
}

void solve(const ll A, const ll B) {
    for (int i = 0; i < MAX_BITS; i++) {
        ll twos = 2LL << i;
        ll cnt_a = count(A - 1, twos);
        ll cnt_b = count(B, twos);
        // printf("twos: %lld, cnt_a: %lld, cnt_b: %lld\n", twos, cnt_a, cnt_b);
        ll cnt = cnt_b - cnt_a;
        if (cnt % 2 == 0) {
            bits[i] = 0;
        } else {
            bits[i] = 1;
        }

        // printf("i: %d, bits[%d]: %d\n", i, i, bits[i]);
    }
}

int main(void) {
    ll A, B;
    cin >> A >> B;

    solve(A, B);

    ll ans = 0;
    for (int i = 0; i < MAX_BITS; i++) {
        if (bits[i] == 1) {
            ans += 1LL << i;
        }
    }

    cout << ans << endl;

    return 0;
}
