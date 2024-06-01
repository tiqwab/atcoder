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

int main(void) {
    int N, Q;
    ll X;
    cin >> N >> Q >> X;

    vector<ll> ws(N);
    vector<ll> acc(2 * N + 1, 0); // [i, j) by acc[j] - acc[i];
    for (int i = 0; i < N; i++) {
        ll w;
        cin >> w;
        ws[i] = w;
        acc[i + 1] = acc[i] + w;
    }
    ll total = acc[N];

    // 扱いやすさのために累積和をもう一周計算する
    for (int i = N; i < 2 * N; i++) {
        acc[i + 1] = acc[i] + ws[i - N];
    }

#ifdef DEBUG
    printf("acc: \n");
    for (int i = 0; i < 2 * N + 1; i++) {
        printf("%lld ", acc[i]);
    }
    printf("\n");
#endif

    vector<int> edge_to(N);
    vector<ll> edge_count(N, 0);
    for (int i = 0; i < N; i++) {
        ll count = 0;
        ll remain_sum = X;
        if (total < remain_sum) {
            count += (remain_sum / total) * N;
            remain_sum = remain_sum % total;
        }
        if (remain_sum == 0) {
            edge_to[i] = i;
            edge_count[i] = count;
            continue;
        }

        int l = i;
        int r = i + N;
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (acc[mid] - acc[i] < remain_sum) { // [i, mid)
                l = mid;
            } else {
                r = mid;
            }
        }

        count += r - i;
        edge_to[i] = r % N;
        edge_count[i] = count;
    }

#ifdef DEBUG
    printf("edge: \n");
    for (int i = 0; i < N; i++) {
        printf("[%d] to: %d, count: %lld\n", i, edge_to[i], edge_count[i]);
    }
#endif

    vector<int> loop;
    map<int, int> visited; // visited[pos]: 何番目に訪れたか (0-index)
    int pos = 0;
    int pos_loop_started;
    int loop_size;
    while (true) {
        if (visited.find(pos) != visited.end()) {
            // loop detected
            pos_loop_started = visited[pos];
            loop_size = ((int) loop.size()) - pos_loop_started;
            break;
        }
        loop.push_back(pos);
        visited[pos] = ((int) loop.size() - 1);
        pos = edge_to[pos];
    }

#ifdef DEBUG
    printf("pos_loop_started: %d\n", pos_loop_started);
    printf("loop_size: %d\n", loop_size);
#endif

    for (int i = 0 ;i < Q; i++) {
        ll k;
        cin >> k;
        k -= 1;
        if (k < pos_loop_started) {
            printf("%lld\n", edge_count[loop[k]]);
        } else {
            k -= pos_loop_started;
            printf("%lld\n", edge_count[loop[(k % loop_size) + pos_loop_started]]);
        }
    }

    return 0;
}
