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

ll gcd(const ll sx, const ll sy) {
    ll x = min(sx, sy);
    ll y = max(sx, sy);
    ll tmp;
    while (x > 0) {
        tmp = y;
        y = x;
        x = tmp % x;
    }
    return y;
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

EratosthenesSieve *sieve;

vector<int> as;

int main(void) {
    int N;
    cin >> N;

    sieve = new EratosthenesSieve(MAX_N);

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    // check pairwise coprime
    {
        map<int, int> counter;
        bool ok = true;
        for (int i = 0; i < N; i++) {
            map<int, int> pf = sieve->factors(as[i]);
            for (auto p : pf) {
                if (counter[p.first] > 0) {
                    ok = false;
                }
                counter[p.first] += p.second;
            }
        }

        if (ok) {
            cout << "pairwise coprime" << endl;
            goto end;
        }
    }

    // check setwise coprime
    {
        int acc = as[0];
        for (int i = 1; i < N; i++) {
            acc = gcd(acc, as[i]);
        }

        if (acc == 1) {
            cout << "setwise coprime" << endl;
            goto end;
        }
    }

    cout << "not coprime" << endl;

end:
    delete sieve;
    return 0;
}
