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

bool cond(const int limit, const int N, const int K) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        // cnt += (as[i] + limit - 1) / limit;
        cnt += (as[i] - 1) / limit;
    }
    return cnt <= K;
}

int solve(const int N, const int K) {
    int left = 0, right = 1000 * 1000 * 1000 + 1, mid;
    while (right - left > 1) {
        mid = left + (right - left) / 2;
        // printf("left: %d, right: %d, mid: %d\n", left, right, mid);
        if (cond(mid, N, K)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return right;
}

int main(void) {
    int N, K;
    cin >> N >> K;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    cout << solve(N, K) << endl;

    return 0;
}
