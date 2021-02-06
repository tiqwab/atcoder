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

vector<pair<int, int>> conds;
vector<pair<int, int>> placements;

int solve(const int N, const int M, const int K) {
    int ans = 0;

    for (int bits = 0; bits < (1 << K); bits++) {
        vector<int> balls(N, 0);

        for (int i = 0; i < K; i++) {
            if (bits & (1 << i)) {
                balls[placements[i].first]++;
            } else {
                balls[placements[i].second]++;
            }
        }

        int oks = 0;
        for (int i = 0; i < M; i++) {
            if (balls[conds[i].first] > 0 && balls[conds[i].second] > 0) {
                oks++;
            }
        }
        chmax(ans, oks);
    }

    return ans;
}

int main(void) {
    int N, M;
    cin >> N >> M;

    conds.resize(M);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        conds[i] = make_pair(A, B);
    }

    int K;
    cin >> K;

    placements.resize(K);
    for (int i = 0; i < K; i++) {
        int C, D;
        cin >> C >> D;
        C--;
        D--;
        placements[i] = make_pair(C, D);
    }

    cout << solve(N, M, K) << endl;

    return 0;
}
