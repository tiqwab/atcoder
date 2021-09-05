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

const int MAX_N = 999999;

EratosthenesSieve *sieve;
vector<bool> numbers;

int main(void) {
    int N, M;
    cin >> N >> M;

    sieve = new EratosthenesSieve(MAX_N);

    set<int> as;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        as.insert(a);
    }

    for (int i = 0; i <= M; i++) {
        numbers.push_back(true);
    }

    for (auto a : as) {
        map<int, int> primes = sieve->factors(a);
        for (auto pa : primes) {
            int acc = pa.first;
            if (acc > M || !numbers[acc]) {
                continue;
            }
            while (acc <= M) {
                numbers[acc] = false;
                acc += pa.first;
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= M; i++) {
        if (numbers[i]) {
            cnt++;
        }
    }
    printf("%d\n", cnt);

    for (int i = 1; i <= M; i++) {
        if (numbers[i]) {
            printf("%d\n", i);
        }
    }

    delete sieve;
    return 0;
}
