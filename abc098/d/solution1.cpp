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

// pos_for_bit[i] contains indexes which contains bit i
vector<vector<int>> pos_for_bit;

ll solve(const int N) {
    ll ans = 0;

    for (int i = 0; i < N; i++) {
        const int start = i;
        int end = N;
#ifdef DEBUG
        printf("start: %d\n", start);
#endif
        for (int bit = 0; bit < 20; bit++) {
            if (as[i] & (1 << bit)) {
                auto it = upper_bound(pos_for_bit[bit].begin(), pos_for_bit[bit].end(), i);
                chmin(end, *it);
#ifdef DEBUG
                printf("  bit: %d, %d\n", bit, *it);
#endif
            } else {
                auto it = upper_bound(pos_for_bit[bit].begin(), pos_for_bit[bit].end(), i);
                it++;
                chmin(end, *it);
#ifdef DEBUG
                printf("  bit: %d, %d\n", bit, *it);
#endif
            }
        }
#ifdef DEBUG
        printf("  end: %d\n", end);
#endif
        ans += end - start;
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

    pos_for_bit.resize(20, vector<int>());
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < N; j++) {
            if (as[j] & (1 << i)) {
                pos_for_bit[i].push_back(j);
            }
        }

        // sentinel
        pos_for_bit[i].push_back(N);
        pos_for_bit[i].push_back(N);
    }

#ifdef DEBUG
    printf("pos_for_bit: \n");
    for (int i = 0; i < 20; i++) {
        printf("  bit %d: ", i);
        for (auto x : pos_for_bit[i]) {
            printf("%d ", x);
        }
        printf("\n");
    }
#endif

    cout << solve(N) << endl;

    return 0;
}
