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

ll solve_for_two(const int N, const string S) {
    ll acc = 0;
    for (int i = 0; i < N; i++) {
        int d = S[i] - '0';
        if (d % 2 == 0) {
            acc += i + 1;
        }
    }
    return acc;
}

ll solve_for_five(const int N, const string S) {
    ll acc = 0;
    for (int i = 0; i < N; i++) {
        int d = S[i] - '0';
        if (d % 5 == 0) {
            acc += i + 1;
        }
    }
    return acc;
}

ll solve_for_others(const int N, const int P, const string S) {
    // {remain, nums}
    map<ll, ll> m;
    ll acc = 0;
    ll x = 0;
    m[0]++;
    ll tenfactor = 1;
    for (int i = 0; i < N; i++) {
        int d = S[i] - '0';
        x = (x + (d * tenfactor) % P) % P;
        acc += m[x];
        m[x]++;
        tenfactor = (tenfactor * 10) % P;
        // printf("i: %d, acc: %d, x: %lld\n", i, acc, x.x);
    }
    return acc;
}

int main(void) {
    int N, P;
    string S;
    cin >> N >> P >> S;

    if (P == 2) {
        cout << solve_for_two(N, S) << endl;
    } else if (P == 5) {
        cout << solve_for_five(N, S) << endl;
    } else {
        reverse(S.begin(), S.end());
        cout << solve_for_others(N, P, S) << endl;
    }

    return 0;
}
