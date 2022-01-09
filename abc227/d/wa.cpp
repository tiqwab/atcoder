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

const ll INF = LONG_LONG_MAX / 2;

vector<ll> as;

ll solve(const int N, const int K) {
    priority_queue<ll, vector<ll>, greater<ll>> q;
    for (int i = 0; i < K; i++) {
        q.push(as[i]);
    }

    for (int i = K; i < N; i++) {
        auto x = q.top();
        q.pop();
        q.push(x + as[i]);
    }

    return q.top();
}

// This approach is wrong.
// The example of wrong answer is:
// 5 4
// 5 10 7 5 8
//
// This program answers 7, but the correct answer is 8.
int main(void) {
    int N, K;
    cin >> N >> K;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        as[i] = a;
    }

    sort(as.begin(), as.end());
    reverse(as.begin(), as.end());

    cout << solve(N, K) << endl;

    return 0;
}
