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

ll INF = LONG_LONG_MAX / 2;

vector<int> to;
vector<ll> score;

ll solve(const int start, const int N, const int K) {
    vector<ll> loop;
    ll max_for_loop = -INF;
    ll sum_for_loop = 0;
    int k1 = 0;
    {
        int cur = start;
        while (1) {
            cur = to[cur];
            sum_for_loop += score[cur];
            chmax(max_for_loop, sum_for_loop);
            k1++;
            if (cur == start || k1 == K) {
                break;
            }
        }
    }

    // in the case K is smaller than loop or repeating loop decreases the score
    if (k1 == K) {
#ifdef DEBUG
        printf("loop is small: %d\n", k1);
#endif
        return max_for_loop;
    }
    if (sum_for_loop <= 0) {
#ifdef DEBUG
        printf("negative loop: %lld\n", sum_for_loop);
#endif
        return max_for_loop;
    }

    assert(max_for_loop > 0);
    assert(sum_for_loop > 0);

    // repeating loop increases the score, so do it as many as possible
    // -> this is actually not true. see the comment of loop_cnt.
    const int loop_size = k1;

    /*
     * Have to decrease 1 from loop_cnt otherwise it fails with a test case like:
     * 5 7
     * 2 3 4 5 1
     * 3 3 3 -4 -4
     * The score of a loop is only 1, but we can get 9 by traveling 5 -> 1 -> 2 -> 3.
     */
    // const int loop_cnt = K / loop_size;
    const int loop_cnt = K / loop_size - 1;

#ifdef DEBUG
    printf("loop size is %d\n", loop_size);
#endif
    ll s = sum_for_loop * loop_cnt;

    ll ans = s;
    int k2 = loop_cnt * loop_size;
    if (k2 < K) {
        int cur = start;
        while (1) {
            cur = to[cur];
            s += score[cur];
            chmax(ans, s);
            k2++;
            if (k2 == K) {
                break;
            }
        }
    }

    assert(ans >= 0);

    return ans;
}

int main(void) {
    int N, K;
    cin >> N >> K;

    to.resize(N);
    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        p--;
        to[i] = p;
    }

    score.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> score[i];
    }

    ll ans = -INF;
    for (int start = 0; start < N; start++) {
        ll cand = solve(start, N, K);
#ifdef DEBUG
        printf("maximum is %lld from %d\n", cand, start);
#endif
        chmax(ans, cand);
    }
    cout << ans << endl;

    return 0;
}
