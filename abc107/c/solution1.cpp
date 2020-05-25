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

// points larger than or equal to 0.
vector<int> ps;
// points smaller than zero.
vector<int> ms;

ll solve(const int N, const int K) {
    // maybe int is enough...
    ll ans = INF;

    for (int num_of_ps = 0; num_of_ps <= K; num_of_ps++) {
        int num_of_ms = K - num_of_ps;
        if (num_of_ps > (int) (ps.size() - 1) || num_of_ms > (int) (ms.size() - 1)) {
            continue;
        }

        // printf("num_of_ps: %d, num_of_ms: %d\n", num_of_ps, num_of_ms);

        // p -> m
        {
            ll cand = 0;
            cand += ps[num_of_ps];
            if (num_of_ms > 0) {
                cand += ps[num_of_ps] - ms[num_of_ms];
            }
            // printf("p->m: %lld\n", cand);
            chmin(ans, cand);
        }

        // m -> p
        {
            ll cand = 0;
            cand += abs(ms[num_of_ms]);
            if (num_of_ps > 0) {
                cand += ps[num_of_ps] - ms[num_of_ms];
            }
            // printf("m->p: %lld\n", cand);
            chmin(ans, cand);
        }
    }

    return ans;
}

int main(void) {
    int N, K;
    cin >> N >> K;

    ps.push_back(0); // dummy
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x >= 0) {
            ps.push_back(x);
        } else {
            ms.push_back(x);
        }
    }
    ms.push_back(0); // dummy
    reverse(ms.begin(), ms.end());

    cout << solve(N, K) << endl;

    return 0;
}
