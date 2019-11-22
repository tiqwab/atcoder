#include <cmath>
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

const ll MOD = 1000000007;
const int MAX =1000000;

ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll solve(const int sx, const int sy) {
    int x = sx, y = sy;
    int n = 0, k = 0;

    while (y < 2 * x) {
        x--;
        y++;
    }

    if (y != 2 * x) {
        return 0LL;
    }

    n = x + 1;
    k = sx - x + 1;

    // cout << n << "," << k << endl;

    return COM(n - 1, k - 1);
}

int main(void) {
    int x, y;
    cin >> x >> y;

    COMinit();

    printf("%lld\n", solve(x, y));
    
    return 0;
}
