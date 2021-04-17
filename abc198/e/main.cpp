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

const int MAX_C = 100000;

vector<int> cs;

vector<vector<int>> edges;

void dfs(const int cur_v, const int prev_v, vector<int> &counter,
        vector<bool> &is_good, const int N) {
    if (counter[cs[cur_v]] == 0) {
        is_good[cur_v] = true;
    }

    counter[cs[cur_v]]++;

    for (auto next_v : edges[cur_v]) {
        if (next_v != prev_v) {
            dfs(next_v, cur_v, counter, is_good, N);
        }
    }

    counter[cs[cur_v]]--;
}

int main(void) {
    int N;
    cin >> N;

    cs.resize(N);
    for (int i = 0; i < N; i++) {
        int c;
        cin >> c;
        c--;
        cs[i] = c;
    }

    edges.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    vector<int> counter(MAX_C, 0);
    vector<bool> is_good(N, false);

    dfs(0, -1, counter, is_good, N);

    for (int i = 0; i < N; i++) {
        if (is_good[i]) {
            printf("%d\n", i + 1);
        }
    }

    return 0;
}
