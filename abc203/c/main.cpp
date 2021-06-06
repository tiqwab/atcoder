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

int main(void) {
    int N, K;
    cin >> N >> K;

    vector<pair<ll, ll>> pos_to_sum;
    {
        map<ll, ll> m;
        for (int i = 0; i < N; i++) {
            ll A, B;
            cin >> A >> B;
            m[A] += B;
        }
        for (auto p : m) {
            pos_to_sum.push_back(p);
        }
        sort(pos_to_sum.begin(), pos_to_sum.end());
    }

    ll cur_pos = K;
    ll cur_i = 0;
    while (cur_i < (int) pos_to_sum.size() && cur_pos >= pos_to_sum[cur_i].first) {
        cur_pos += pos_to_sum[cur_i].second;
        cur_i++;
    }

    cout << cur_pos << endl;
    return 0;
}
