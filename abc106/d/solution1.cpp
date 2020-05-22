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

const int MAX_N = 500;

vector<int> trains[MAX_N + 1];

int main(void) {
    int N, M, Q;
    cin >> N >> M >> Q;

    for (int i = 0; i < M; i++) {
        int L, R;
        cin >> L >> R;
        trains[L].push_back(R);
    }

    for (int i = 0; i <= N; i++) {
        sort(trains[i].begin(), trains[i].end());
    }

    for (int i = 0; i < Q; i++) {
        int p, q;
        cin >> p >> q;
        // printf("[%d, %d]\n", p, q);

        int ans = 0;
        for (int j = p; j <= q; j++) {
            auto it = upper_bound(trains[j].begin(), trains[j].end(), q);
            int dist = distance(trains[j].begin(), it);
            // printf("start: %d, += %d\n", j, dist);
            ans += dist;
        }
        cout << ans << endl;
    }

    return 0;
}
