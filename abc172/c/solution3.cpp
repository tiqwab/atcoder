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

vector<ll> ss_a;
vector<ll> ss_b;

int main(void) {
    int N, M;
    ll K;
    cin >> N >> M >> K;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    bs.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> bs[i];
    }

    ss_a.resize(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        ss_a[i] = ss_a[i - 1] + as[i - 1];
    }

    ss_b.resize(M + 1, 0);
    for (int i = 1; i <= M; i++) {
        ss_b[i] = ss_b[i - 1] + bs[i - 1];
    }

    int ans = 0;

    int num_b = M;
    for (int num_a = 0; num_a <= N; num_a++) {
        ll rem = K - ss_a[num_a];
        if (rem < 0) {
            break;
        }
        while (num_b > 0 && ss_b[num_b] > rem) {
            num_b--;
        }
        // printf("num_a: %d, num_b: %d\n", num_a, num_b);
        chmax(ans, num_a + num_b);
    }

    cout << ans << endl;

    return 0;
}
