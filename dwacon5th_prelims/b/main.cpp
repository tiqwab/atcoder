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

vector<ll> a;
vector<ll> sums;

void calc_sums(const ll N) {
    vector<ll> part_sums(N + 1, 0);
    for (int i = 0; i < N; i++) {
        part_sums[i + 1] = part_sums[i] + a[i];
    }

    int ind = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            sums[ind] = part_sums[j + 1] - part_sums[i];
            ind++;
        }
    }
}

ll solve(const int cur_bit, const vector<ll> &g, const ll N, const ll K) {
    if (cur_bit < 0) return 0;

    ll count = 0;
    vector<ll> next_g;

    for (int i = 0; i < (int) g.size(); i++) {
        if (g[i] & (1LL << cur_bit)) {
            count++;
            next_g.push_back(g[i]);
        }
    }
    if (count >= K) {
        return (1LL << cur_bit) | solve(cur_bit - 1, next_g, N, K);
    } else {
        return solve(cur_bit - 1, g, N, K);
    }
}

int main(void) {
    ll N, K;
    cin >> N >> K;

    a.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    ll sums_len = N * (N + 1) / 2;
    sums.resize(sums_len);
    calc_sums(N);

    // for (int i = 0; i < sums_len; i++) {
    //     cout << sums[i] << endl;
    // }
    // // sort by descending order
    // sort(sums.begin(), sums.end(), [](const ll &a, const ll &b) {
    //         return a > b;
    //         });

    int start_bit = -1;
    for (int i = 40; i >= 0; i--) {
        ll count = 0;
        for (int j = 0; j < sums_len; j++) {
            if (sums[j] & (1LL << i)) {
                count++;
            }
        }
        if (count >= K) {
            start_bit = i;
            break;
        }
    }

    if (start_bit == -1) {
        cout << "0" << endl;
        return 0;
    }

    vector<ll> g;
    for (int i = 0; i < sums_len; i++) {
        if (sums[i] & (1LL << start_bit)) {
            g.push_back(sums[i]);
        }
    }

    cout << solve(start_bit, g, N, K) << endl;
    return 0;
}
