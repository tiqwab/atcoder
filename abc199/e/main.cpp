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

// Xi to [{Yi, Zi}]
map<int, vector<pair<int, int>>> conds;

vector<ll> dp;

int calc_bits(int x) {
    int ans = 0;
    while (x > 0) {
        if (x & 1) {
            ans++;
        }
        x = x >> 1;
    }
    return ans;
}

bool check(const pair<int, int> cond, const int group, const int N) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (group & (1 << i)) {
            if (i + 1 <= cond.first) {
                cnt++;
            }
        }
    }
    return cnt <= cond.second;
}

int main(void) {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int X, Y, Z;
        cin >> X >> Y >> Z;
        conds[X].push_back(make_pair(Y, Z));
    }

    dp.resize(1 << N, 0);
    dp[0] = 1;

    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            const int cur_group = i;
            const int cur_group_size = calc_bits(cur_group);
            const int next_member = 1 << j;
            const int next_group = cur_group | next_member;
            if (cur_group == next_group) {
                continue;
            }
            const int next_group_size = cur_group_size + 1;

            bool ok = true;
            for (auto cond : conds[next_group_size]) {
                if (!check(cond, next_group, N)) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                dp[next_group] += dp[cur_group];
            }
        }
    }

#ifdef DEBUG
    printf("dp: \n");
    for (int i = 0; i < (1 << N); i++) {
        cout << dp[i] << " ";
    }
    printf("\n");
#endif

    cout << dp[(1 << N) - 1] << endl;

    return 0;
}
