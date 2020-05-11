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

vector<vector<int>> edges;

// return -1 if loop is not found
int find_loop(int cur, vector<bool> &visited, ll &cnt) {
    // printf("cur: %d\n", cur);
    if (visited[cur]) {
        return cur;
    }
    visited[cur] = true;
    cnt++;
    return find_loop(edges[cur][0], visited, cnt);

    // for (auto next : edges[cur]) {
    //     cnt++;
    //     int ans = find_loop(next, visited, cnt, N);
    //     if (ans != -1) {
    //         return ans;
    //     }
    // }
    // return -1;
}

void find_towns_in_loop(int cur, vector<bool> &visited, vector<int> &acc) {
    if (visited[cur]) {
        return;
    }
    acc.push_back(cur);
    visited[cur] = true;
    find_towns_in_loop(edges[cur][0], visited, acc);
}

int main(void) {
    int N;
    ll K;
    cin >> N >> K;

    edges.resize(N);
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        t--;
        // printf("%d -> %d\n", i, t);
        edges[i].push_back(t);
    }

    ll cnt_till_loop = 0;
    int loop_start;
    {
        vector<bool> visited(N, false);
        loop_start = find_loop(0, visited, cnt_till_loop);
    }
    assert(loop_start >= 0);

    // printf("loop_start: %d, cnt_till_loop: %lld\n", loop_start, cnt_till_loop);

    if (K < cnt_till_loop) {
        loop_start = 0;
    }

    vector<int> towns_in_loop;
    {
        vector<bool> visited(N, false);
        find_towns_in_loop(loop_start, visited, towns_in_loop);
    }

    // for (auto v : towns_in_loop) {
    //     cout << v << " ";
    // }
    // cout << endl;

    if (K < cnt_till_loop) {
        cout << towns_in_loop[K] + 1 << endl;
    } else {
        K -= cnt_till_loop;
        K = K % ((ll) towns_in_loop.size());
        cout << towns_in_loop[K] + 1 << endl;
    }

    return 0;
}
