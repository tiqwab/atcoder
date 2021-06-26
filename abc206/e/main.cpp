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

// ref. YouTube ABC 152 E
class EratosthenesSieve {
    public:
        const int N;

        EratosthenesSieve(const int N): N(N) {
            numbers.resize(N + 1, 0);
            init();
        }

        // assume that n > 0 && n <= N
        map<int, int> factors(int n) {
            // assert(n > 0 && n <= N); 
            map<int, int> res;
            while (n > 1) {
                res[numbers[n]]++;
                n /= numbers[n];
            }
            return res;
        }

        void primes(vector<int> &p) {
            for (int i = 2; i <= N; i++) {
                if (is_prime(i)) {
                    p.push_back(i);
                }
            }
        }

        // assume that n > 0 && n <= N
        bool is_prime(const int n) {
            // assert(n > 0 && n <= N);
            return numbers[n] == n;
        }

    private:
        vector<int> numbers; // numbers[i] means minimum prime factor for i (e.g. numbers[12] = 2)

        void init() {
            // O(N * log(logN)) ???
            int i = 2;
            for (; i * i <= N; i++) {
                if (numbers[i] == 0) {
                    numbers[i] = i;
                    for (int j = i * i; j <= N; j += i) {
                        if (numbers[j] == 0) {
                            numbers[j] = i;
                        }
                    }
                }
            }
            for (; i <= N; i++) {
                if (numbers[i] == 0) {
                    numbers[i] = i;
                }
            }
        }
};

const int MAX_N = 1000010;

int main(void) {
    int L, R;
    cin >> L >> R;

    ll ans = 0;

    EratosthenesSieve *sieve = new EratosthenesSieve(MAX_N);

    for (int x = 2; x < R; x++) {
        auto x_factors = sieve->factors(x);

        const int prime_kinds = (int) x_factors.size();
        int acc = 1;

        {
            bool should_skip = false;
            for (auto p : x_factors) {
                acc *= p.first;
                if (p.second > 1) {
                    should_skip = true;
                    break;
                }
            }
            if (should_skip) {
                continue;
            }
        }

        ll n = R / acc - (L - 1) / acc;
        if (prime_kinds % 2 == 0) {
            ans -= n * (n - 1) / 2;
        } else {
            ans += n * (n - 1) / 2;
        }
    }

    for (int x = max(2, L); x < R; x++) {
        ans -= R / x - 1;
    }

    cout << ans * 2 << endl;

    delete sieve;
    return 0;
}
