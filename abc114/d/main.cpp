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

const int MAX_N = 1000;

// {number, count}
map<int, int> m;

vector<int> acc;

int main(void) {
    int N;
    cin >> N;

    EratosthenesSieve *sieve = new EratosthenesSieve(MAX_N);
    for (int i = 2; i <= N; i++) {
        auto facts = sieve->factors(i);
        for (auto &p : facts) {
            m[p.first] += p.second;
        }
    }
    // for (auto &p : m) {
    //     printf("%d: %d\n", p.first, p.second);
    // }
    // printf("\n");

    // preapre acc
    acc.resize(100 + 1, 0);
    for (auto &p : m) {
        acc[p.second]++;
    }
    for (int i = 100; i > 0; i--) {
        acc[i - 1] += acc[i];
    }
    // for (int i = 0; i < (int) acc.size(); i++) {
    //     printf("%d: %d\n", i, acc[i]);
    // }
    // printf("\n");

    int ans = 0;
    ans += acc[75 - 1];
    ans += max(0, (acc[3 - 1] - 1) * acc[25 - 1]);
    ans += max(0, (acc[5 - 1] - 1) * acc[15 - 1]);
    ans += max(0, (acc[3 - 1] - 2) * acc[5 - 1] * (acc[5 - 1] - 1) / 2);

    cout << ans << endl;

    delete sieve;
    return 0;
}
