#include <algorithm>
#include <iostream>
#include <vector>

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

const ll MAX = 1000000LL;

vector<ll> list_primes() {
    vector<bool> numbers(MAX, true);
    vector<ll> primes;
    primes.push_back(2);
    primes.push_back(3);

    numbers[0] = 0;
    numbers[1] = 0;
    for (int i = 4; i <  MAX; i += 2) {
        numbers[i] = false;
    }
    for (int i = 6; i < MAX; i += 3) {
        numbers[i] = false;
    }
    for (int i = 5; i < MAX; i++) {
        if (numbers[i]) {
            primes.push_back(i);
            for (int j = i + i; j < MAX; j += i) {
                numbers[j] = false;
            }
        }
    }

    return primes;
}

int main(void) {
    ll X;
    cin >> X;

    vector<ll> primes = list_primes();
    // for (int i = 0; i < (int) primes.size(); i++) {
    //     cout << primes[i] << endl;
    // }

    auto ans = lower_bound(primes.begin(), primes.end(), X);
    cout << *ans << endl;

    return 0;
}
