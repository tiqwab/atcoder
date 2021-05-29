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

ll calc(const int a, map<int, vector<int>> &b_val_to_idx, vector<int> &c_cnt, const int N) {
    static vector<ll> memo(N + 1, -1);
    if (memo[a] >= 0) {
        return memo[a];
    }

    ll ans = 0;
    vector<int> bis = b_val_to_idx[a];
    for (auto bi : bis) {
        ans += c_cnt[bi];
    }

    memo[a] = ans;
    return ans;
}

int main(void) {
    int N;
    cin >> N;

    vector<int> as(N), bs(N), cs(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> bs[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> cs[i];
    }

    // b_val_to_idx[i] is indices of bs whose value is i
    map<int, vector<int>> b_val_to_idx;
    for (int i = 0; i < N; i++) {
        b_val_to_idx[bs[i]].push_back(i);
    }

    // c_cnt[i] is the number of cs whose value is i
    vector<int> c_cnt(N, 0);
    for (int i = 0; i < N; i++) {
        c_cnt[cs[i] - 1]++;
    }

#ifdef DEBUG
    printf("c_cnt: \n");
    for (int i = 0; i < N; i++) {
        cout << c_cnt[i] << " ";
    }
    cout << endl;
#endif

    ll ans = 0;

    for (int i = 0; i < N; i++) {
        const int a = as[i];
        ans += calc(a, b_val_to_idx, c_cnt, N);
        // vector<int> bis = b_val_to_idx[a];
        // for (auto bi : bis) {
        //     ans += c_cnt[bi];
        // }
    }

    cout << ans << endl;

    return 0;
}
