#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <map>

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

const int MAX_A = 1000000;
const ll MOD = 1000000007;

vector<ll> A;
vector<map<int, int>> ms;

// auto mod int
// ref. https://github.com/atcoder-live/library/blob/master/mint.cpp
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%MOD+MOD)%MOD){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += MOD-a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= MOD;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime MOD
  mint inv() const {
    return pow(MOD-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};

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

int main(void) {
    int N;
    cin >> N;

    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    EratosthenesSieve *sieve = new EratosthenesSieve(MAX_A);

    // {prime, count}
    map<int, int> lcm;
    for (int i = 0; i < N; i++) {
        map<int, int> m = sieve->factors(A[i]);
        for (auto &p : m) {
            int prime = p.first;
            int count = p.second;
            chmax(lcm[prime], count);
        }
    }

    mint lcm_mod = mint(1LL);
    for (auto &p : lcm) {
        for (int i = 0; i < p.second; i++) {
            lcm_mod = lcm_mod * p.first;
        }
    }

    mint acc = mint(0LL);
    for (int i = 0; i < N; i++) {
        mint x = lcm_mod * mint(A[i]).pow(MOD - 2);
        acc = (acc + x);
    }

    cout << acc.x << endl;

    delete sieve;
    return 0;
}
