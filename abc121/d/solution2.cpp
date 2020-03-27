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

// ll calc(const ll x) {
//     if (x % 2 == 0) {
//         ll cnt = x / 2;
//         if (cnt % 2 == 0) {
//             return x;
//         } else {
//             return x ^ 1;
//         }
//     } else {
//         ll cnt = (x + 1) / 2;
//         return cnt % 2;
//     }
// }

ll calc(const ll x) {
    if (x % 4 == 0) return x;
    else if (x % 4 == 1) return 1LL;
    else if (x % 4 == 2) return x ^ 1LL;
    else return 0LL;
}

ll solve(const ll A, const ll B) {
    ll v_a = calc(A - 1);
    ll v_b = calc(B);
    return v_a ^ v_b;
}

int main(void) {
    ll A, B;
    cin >> A >> B;

    cout << solve(A, B) << endl;

    return 0;
}
