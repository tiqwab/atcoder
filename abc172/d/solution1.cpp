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

const int MAX_N = 10 * 1000 * 1000 + 1;

int main(void) {
    int N;
    cin >> N;

    EratosthenesSieve *sieve = new EratosthenesSieve(MAX_N);

    ll ans = 1;
    for (int i = 2; i <= N; i++) {
        map<int, int> fs = sieve->factors(i);
        ll acc = i;
        for (auto &p : fs) {
            acc *= p.second + 1;
        }
        // printf("i: %d, acc: %lld\n", i, acc);
        ans += acc;
    }

    cout << ans << endl;

    delete sieve;
    return 0;
}
