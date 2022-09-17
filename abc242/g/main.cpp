#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>
#include <math.h>

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
vector<int> ls;
vector<int> rs;

int main(void) {
    int N;
    cin >> N;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
        as[i]--;
    }

    int Q;
    cin >> Q;

    ls.resize(Q);
    rs.resize(Q);
    for (int i = 0; i < Q; i++) {
        cin >> ls[i];
        cin >> rs[i];
        ls[i]--;
        rs[i]--;
    }

    const int w = max(1, N / ((int) sqrt(Q)));

    vector<int> qis(Q);
    iota(qis.begin(), qis.end(), 0);
    sort(qis.begin(), qis.end(), [&](const int &i, const int &j) {
        if (rs[i] / w != rs[j] / w) {
            return rs[i] / w < rs[j] / w;
        }
        return ls[i] < ls[j];
    });

    int cur_r = -1;
    int cur_l = 0;
    int acc = 0;
    vector<int> ans(Q, 0);
    vector<int> cnt(N, 0);

    for (auto qi : qis) {
        const int next_r = rs[qi];
        const int next_l = ls[qi];
        while (cur_r < next_r) {
            cur_r++;
            acc -= cnt[as[cur_r]] / 2; 
            cnt[as[cur_r]]++;
            acc += cnt[as[cur_r]] / 2; 
        }
        while (cur_r > next_r) {
            acc -= cnt[as[cur_r]] / 2; 
            cnt[as[cur_r]]--;
            acc += cnt[as[cur_r]] / 2; 
            cur_r--;
        }
        while (cur_l < next_l) {
            acc -= cnt[as[cur_l]] / 2; 
            cnt[as[cur_l]]--;
            acc += cnt[as[cur_l]] / 2; 
            cur_l++;
        }
        while (cur_l > next_l) {
            cur_l--;
            acc -= cnt[as[cur_l]] / 2; 
            cnt[as[cur_l]]++;
            acc += cnt[as[cur_l]] / 2; 
        }
        ans[qi] = acc;
    }

    for (int i = 0; i < Q; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}
