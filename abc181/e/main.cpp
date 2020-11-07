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

vector<int> Hs;
vector<int> Ws;

int main(void) {
    int N, M;
    cin >> N >> M;

    Hs.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> Hs[i];
    }
    sort(Hs.begin(), Hs.end());

    Ws.resize(M + 2);
    Ws[0] = -1 * 1000 * 1000 * 1000 * 2;
    for (int i = 1; i <= M; i++) {
        cin >> Ws[i];
    }
    Ws[M + 1] = 1000 * 1000 * 1000 * 2;
    sort(Ws.begin(), Ws.end());

    map<int, int> memo_pairs;
    ll acc = 0;
    for (int i = 0; i < N - 1; i += 2) {
        memo_pairs[i] = i + 1;
        memo_pairs[i + 1] = i;
        acc += Hs[i + 1] - Hs[i];
    }

#ifdef DEBUG
    printf("memo_pairs: \n");
    for (int i = 0; i < N; i++) {
        printf("  %d: %d\n", i, memo_pairs[i]);
    }
    cout << endl;
#endif

    ll ans = LONG_LONG_MAX / 2;
    for (int i = N - 1; i >= 0; i--) {
        int h = Hs[i];
        auto it = lower_bound(Ws.begin(), Ws.end(), h);
        ll diff = min(abs(h - *(it)), abs(h - *(it - 1)));

#ifdef DEBUG
        printf("i: %d, acc: %lld, h: %d, diff: %lld\n", i, acc, h, diff);
#endif
        chmin(ans, acc + diff);

        if (i == 0) {
            continue;
        }

        int next = i - 1;
        int next_pair = memo_pairs[next];
#ifdef DEBUG
        printf("next: %d, next_pair: %d\n", next, next_pair);
#endif
        acc -= abs(Hs[next] - Hs[next_pair]);
        acc += abs(Hs[i] - Hs[next_pair]);
        memo_pairs[i] = next_pair;
        memo_pairs[next_pair] = i;
    }

    cout << ans << endl;

    return 0;
}
