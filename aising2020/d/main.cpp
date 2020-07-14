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

const int MAX_N = 200000;

vector<ll> power_for_one;
vector<ll> power_for_zero;

int count_bit(const string &S) {
    int ans = 0;

    for (int i = 0; i < (int) S.size(); i++) {
        if (S[i] == '1') {
            ans++;
        }
    }

    return ans;
}

ll do_calc(const int mod, const vector<ll> &power, const string &S) {
    ll v = 0;
    string T = S;
    reverse(T.begin(), T.end());
    for (int i = 0; i < (int) T.size(); i++) {
        if (T[i] == '1') {
            v = (v + power[i]) % mod;
        }
    }

    return v;
}

ll calc_for_one(const int mod, const vector<ll> &power, const string &S) {
    if (mod == 0) {
        return 0;
    } else {
        return do_calc(mod, power, S);
    }
}

ll calc_for_zero(const int mod, const vector<ll> &power, const string &S) {
    return do_calc(mod, power, S);
}

void prepare_power(const int mod, vector<ll> &power) {
    power.resize(MAX_N + 1, 0);
    if (mod == 0) {
        return;
    }

    power[0] = 1 % mod;

    for (int i = 1; i <= MAX_N; i++) {
        power[i] = (power[i - 1] * 2) % mod;
    }

}

int main(void) {
    int N;
    cin >> N;
    string S;
    cin >> S;

    const int bit_count = count_bit(S);
    const int mod_for_one = bit_count - 1;
    const int mod_for_zero = bit_count + 1;

    prepare_power(mod_for_one, power_for_one);
    prepare_power(mod_for_zero, power_for_zero);

    ll second_step_for_one = calc_for_one(mod_for_one, power_for_one, S);
    ll second_step_for_zero = calc_for_zero(mod_for_zero, power_for_zero, S);

    for (int i = 0; i < N; i++) {
        ll x;
        ll mod;
        if (S[i] == '1') {
            mod = mod_for_one;
            x = second_step_for_one;
            if ((x += mod - power_for_one[N - 1 - i]) >= mod) x -= mod;
        } else {
            mod = mod_for_zero;
            x = second_step_for_zero;
            x = (x + power_for_zero[N - 1 - i]) % mod;
        }

        // printf("%d: %lld\n", i, x);

        if (mod == 0) {
            printf("%d\n", 0);
            continue;
        }

        int cnt = 1;
        while (x > 0) {
            int bit_count = __builtin_popcountll(x);
            x = x % bit_count;
            cnt++;
        }

        printf("%d\n", cnt);
    }

    return 0;
}
