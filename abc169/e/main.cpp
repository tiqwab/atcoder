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

vector<int> as;
vector<int> bs;

ll solve(const int N) {
    if (N % 2 == 0) {
        ll a1 = as[N / 2 - 1];
        ll a2 = as[N / 2];
        ll b1 = bs[N / 2 - 1];
        ll b2 = bs[N / 2];
        // printf("a1: %lld, a2: %lld, b1: %lld, b2: %lld\n", a1, a2, b1, b2);
        return ((b1 + b2) - (a1 + a2)) + 1;
    } else {
        ll avg1 = as[N / 2];
        ll avg2 = bs[N / 2];
        // printf("avg1: %lld, avg2: %lld\n", avg1, avg2);
        return (avg2 - avg1) + 1LL;
    }
}

int main(void) {
    int N;
    cin >> N;

    as.resize(N);
    bs.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i] >> bs[i];
    }
    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());

    cout << solve(N) << endl;

    return 0;
}
