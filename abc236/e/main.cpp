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

bool check_average(const ll border, vector<ll> as, const int N) {
    for (int i = 0; i < N; i++) {
        as[i] = as[i] - border;
    }

    vector<ll> dp(N, 0);
    dp[0] = as[0];
    dp[1] = max(dp[0] + as[1], as[1]);
    for (int i = 2; i < N; i++) {
        dp[i] = max(dp[i - 2] + as[i], dp[i - 1] + as[i]);
    }
    return dp[N - 2] > 0 || dp[N - 1] > 0;
}

double calculate_average(const vector<int> as, const int N) {
    // expected precision is < 10^3, so multiply each element by 1000
    vector<ll> bs(N);
    for (int i = 0; i < N; i++) {
        bs[i] = ll(as[i]) * 1000LL;
    }

    ll left = 0, right = 1000LL * 1000LL * 1000LL * 1000LL + 1;
    while (right - left > 1) {
        const ll mid = left + (right - left) / 2;
        if (check_average(mid, bs, N)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return double(left) / 1000;
}

bool check_median(const int border, vector<int> as, const int N) {
    for (int i = 0; i < N; i++) {
        if (as[i] < border) {
            as[i] = -1;
        } else {
            as[i] = 1;
        }
    }

    vector<int> dp(N, 0);
    dp[0] = as[0];
    dp[1] = max(dp[0] + as[1], as[1]);
    for (int i = 2; i < N; i++) {
        dp[i] = max(dp[i - 2] + as[i], dp[i - 1] + as[i]);
    }
    return dp[N - 2] > 0 || dp[N - 1] > 0;
}

int calculate_median(const vector<int> as, const int N) {
    int left = 0, right = 1000 * 1000 * 1000 + 1;
    while (right - left > 1) {
        const int mid = left + (right - left) / 2;
        if (check_median(mid, as, N)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return left;
}

int main(void) {
    int N;
    cin >> N;

    vector<int> as;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        as.push_back(a);
    }

    // calculate average
    printf("%.3f\n", calculate_average(as, N));

    // calculate median
    printf("%d\n", calculate_median(as, N));

    return 0;
}
