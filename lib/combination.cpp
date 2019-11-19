#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

/*
 * ref. http://drken1215.hatenablog.com/entry/2018/06/08/210000
 *
 * usage:
 *
 * Combination *c;
 * 
 * const int MOD = 1000000007;
 * const int MAX_N = 100000;
 * 
 * int main(void) {
 *     int n, k;
 *     cin >> n >> k;
 *     c = new Combination(2 * MAX_N, MOD);
 *     cout << c->com(n + k - 1, k) << endl;
 *     delete(c);
 *     return 0;
 * }
 */
class Combination {
    public:
        const int max;
        const int mod;
        vector<ll> fac, finv, inv;

        Combination(int max, int mod) : max(max), mod(mod), fac(max), finv(max), inv(max) {
            init();
        }

        ll com(int n, int k) {
            if (n < k) return 0LL;
            if (n < 0 || k < 0) return 0LL;
            // return (fac[n] * ((finv[k] * finv[n - k]) % mod)) % mod;
            return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
        }

    private:
        void init() {
            fac[0] = fac[1] = 1;
            finv[0] = finv[1] = 1;
            inv[1] = 1;
            for (int i = 2; i < max; i++){
                fac[i] = fac[i - 1] * i % mod;
                inv[i] = mod - inv[mod%i] * (mod / i) % mod;
                finv[i] = finv[i - 1] * inv[i] % mod;
            }
        }
};

Combination *c;

const int MOD = 1000000007;
const int MAX_N = 100000;

// ref. https://abc021.contest.atcoder.jp/tasks/abc021_d
int main(void) {
    int n, k;
    cin >> n >> k;

    c = new Combination(2 * MAX_N, MOD);

    cout << c->com(n + k - 1, k) << endl;

    delete(c);
    return 0;
}


// const int MAX = 2 * 100000 + 1;
// const int MOD = 1000000007;
// 
// long long fac[MAX], finv[MAX], inv[MAX];
// 
// // テーブルを作る前処理
// void COMinit() {
//     fac[0] = fac[1] = 1;
//     finv[0] = finv[1] = 1;
//     inv[1] = 1;
//     for (int i = 2; i < MAX; i++){
//         fac[i] = fac[i - 1] * i % MOD;
//         inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
//         finv[i] = finv[i - 1] * inv[i] % MOD;
//     }
// }
// 
// // 二項係数計算
// long long COM(int n, int k){
//     if (n < k) return 0;
//     if (n < 0 || k < 0) return 0;
//     return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
// }
// 
// int main(void) {
//     int n, k;
//     cin >> n >> k;
// 
//     COMinit();
// 
//     cout << COM(n + k - 1, k) << endl;
//     return 0;
// }
