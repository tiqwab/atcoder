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

const int INF = INT_MAX / 2;

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

vector<int> as;

vector<int> calc_divisors(const int a) {
    vector<int> ans;
    for (int i = 1; i * i <= a; i++) {
        if (a % i == 0) {
            if (i * i == a) {
                ans.push_back(i);
            } else {
                ans.push_back(i);
                ans.push_back(a / i);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main(void) {
    int N;
    cin >> N;

    int min_a = INF;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
        chmin(min_a, as[i]);
    }

    map<int, int> memo;

    for (int i = 0; i < N; i++) {
        vector<int> divisors = calc_divisors(as[i]);
        for (auto d : divisors) {
            if (memo.find(d) == memo.end()) {
                memo[d] = as[i];
            } else {
                memo[d] = gcd(memo[d], as[i]);
            }
        }
    }

    int ans = 0;
    for (auto kv : memo) {
        const int key = kv.first;
        const int val = kv.second;
        if (key <= min_a && key == val) {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
