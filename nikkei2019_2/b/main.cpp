#include <cassert>
#include <iostream>

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

const int MAX_N = 100000;
const ll MOD = 998244353LL;

ll calc(ll base, ll exponent) {
    assert(base > 0);
    assert(exponent >= 0);

    if (exponent == 0) {
        return 1LL;
    }

    ll answer = base % MOD;
    while (--exponent > 0) {
        answer = (answer * (base % MOD)) % MOD;
    }
    return answer;
}

int n;
int d[MAX_N];
int b[MAX_N];

int main(void) {
    cin >> n;

    int max = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        d[i] = x;
        b[x]++;
        if (x > max) {
            max = x;
        }
    }

    if (d[0] != 0 || b[0] != 1) {
        cout << 0 << endl;
        return 0;
    }

    ll answer = 1;
    for (int i = 1; i <= max; i++) {
        if (b[i] == 0) {
            answer = 0;
            break;
        }
        answer = (answer * calc(b[i-1], b[i])) % MOD;
    }

    cout << answer << endl;
    
    return 0;
}
