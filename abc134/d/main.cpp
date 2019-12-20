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

vector<ll> calc_factors(const ll n) {
    vector<ll> factors;
    factors.push_back(1);
    // factors.push_back(n);
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (i * i != n) {
                factors.push_back(i);
                factors.push_back(n / i);
            } else {
                factors.push_back(i);
            }
        }
    }
    return factors;
}

void disp(const vector<int> &xs) {
    for (int i = 0; i < (int) xs.size(); i++) {
        cout << xs[i] << " ";
    }
    cout << endl;
}

void solve(const int N, const vector<ll> &a, vector<ll> &counter, vector<ll> &ans) {
    for (ll n = N; n > 0; n--) {
        // disp(counter);
        if (a[n] == 0) {
            if (counter[n] % 2 == 0) {
                ans[n] = 0;
            } else {
                ans[n] = 1;
                vector<ll> factors = calc_factors(n);
                for (int i = 0; i < (int) factors.size(); i++) {
                    counter[factors[i]]++;
                }
            }
        } else {
            if (counter[n] % 2 == 0) {
                ans[n] = 1;
                vector<ll> factors = calc_factors(n);
                for (int i = 0; i < (int) factors.size(); i++) {
                    counter[factors[i]]++;
                }
            } else {
                ans[n] = 0;
            }
        }

    }
}

int main(void) {
    int N;
    cin >> N;

    vector<ll> a(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    vector<ll> counter(N + 1, 0);
    vector<ll> ans(N + 1, -1);
    ans[0] = 0;
    solve(N, a, counter, ans);

    int num = 0;
    for (int i = 1; i <= N; i++) {
        if (ans[i] == 1) {
            num++;
        }
    }
    cout << num << endl;
    if (num > 0) {
        for (int i = 1; i <= N; i++) {
            if (ans[i] == 1) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
