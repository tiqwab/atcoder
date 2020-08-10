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

vector<int> s_as;
vector<int> s_bs;

int main(void) {
    int N;
    cin >> N;

    as.resize(N);
    bs.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> bs[i];
    }

    s_as.resize(N + 1, 0);
    for (int i = 0; i < N; i++) {
        s_as[i + 1] = s_as[i] + as[i];
    }

    s_bs.resize(N + 1, 0);
    for (int i = 0; i < N; i++) {
        s_bs[i + 1] = s_bs[i] + bs[i];
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int cand = s_as[i] + (s_bs[N] - s_bs[i - 1]);
        // printf("%d: %d\n", i, cand);
        chmax(ans, cand);
    }
    cout << ans << endl;

    return 0;
}
