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

ll solve(const int N) {
    ll ans = 0;

    int acc = 0;
    int end = 0;
    for (int begin = 0; begin < N; begin++) {
        // [begin, end)
        while (end < N && (acc + as[end]) == (acc ^ as[end])) {
            acc += as[end];
            end++;
        }
        ans += end - begin;
        // printf("begin: %d, end: %d, acc: %d, ans: %lld\n", begin, end, acc, ans);

        acc -= as[begin];
    }

    return ans;
}

int main(void) {
    int N;
    cin >> N;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    cout << solve(N) << endl;

    return 0;
}
