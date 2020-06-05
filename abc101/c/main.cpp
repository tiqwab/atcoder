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

int solve(const int N, const int K) {
    int ans = 0;

    int pos = 0;
    while (pos < N - 1) {
        ans++;
        pos += K - 1;
    }

    return ans;
}

int main(void) {
    int N, K;
    cin >> N >> K;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    if (K >= N) {
        cout << 1 << endl;
    } else {
        cout << solve(N, K) << endl;
    }

    return 0;
}
