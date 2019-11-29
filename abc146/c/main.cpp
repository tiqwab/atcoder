#include <iostream>

#include <string.h>
#include <stdio.h>

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

const ll MAX_X = 1000LL * 1000 * 1000 * 1000 * 1000 * 1000;
const ll MAX_N = 1000LL * 1000 * 1000;

ll d(const ll x) {
    char s[128];
    snprintf(s, 128, "%lld", x);
    // printf("%s, %zu\n", s, strlen(s));
    return strlen(s);
}

bool cond(const ll A, const ll B, const ll X, const ll mid) {
    // printf("%lld, %lld, %lld, %lld = %lld\n", A, B, X, mid, (A * mid + B * d(mid)));
    return (A * mid + B * d(mid)) <= X;
}

/*
 * Return the minimum index which satisfies the condition if exists, otherwise -1.
 */
int binary_search(const ll A, const ll B, const ll X) {
    ll left = 0LL, right = MAX_N + 1, mid;
    while (right - left > 1) {
        mid = (left + right) / 2;
        if (cond(A, B, X, mid)) left = mid;
        else right = mid;
    }

    return left;
}

int main(void) {
    ll A, B, X;
    cin >> A >> B >> X;

    ll answer = binary_search(A, B, X);
    if (answer > MAX_N) {
        answer = MAX_N;
    }

    cout << answer << endl;
    
    return 0;
}
