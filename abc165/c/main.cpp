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

vector<tuple<int, int, int, int>> conds;

int calc(const vector<int> &acc, const int N, const int M, const int Q) {
    // for (int i = 0; i < (int) acc.size(); i++) {
    //     cout << acc[i] << " ";
    // }
    // cout << endl;

    int ans = 0;
    for (auto &cond : conds) {
        int a, b, c, d;
        tie(a, b, c, d) = cond;
        if (acc[b] - acc[a] == c) {
            ans += d;
        }
    }

    // printf("calculated: %d\n", ans);

    return ans;
}

void solve(int cur_val, int cur_pos, vector<int> &acc, int &cand, const int N, const int M, const int Q) {
    if (cur_pos == N) {
        chmax(cand, calc(acc, N, M, Q));
        return;
    }

    for (int i = cur_val; i <= M; i++) {
        acc.push_back(i);
        solve(i, cur_pos + 1, acc, cand, N, M, Q);
        acc.pop_back();
    }
}

int main(void) {
    int N, M, Q;
    cin >> N >> M >> Q;

    conds.resize(Q);
    for (int i = 0; i < Q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        conds[i] = tie(a, b, c, d);
    }

    int ans = 0;
    vector<int> acc;
    solve(1, 0, acc, ans, N, M, Q);
    cout << ans << endl;

    return 0;
}
