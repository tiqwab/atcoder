#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

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

void calc_dists(const int cur_pos, const int cur_dist,
        const vector<vector<int> > &edges, map<int, int> &dists, vector<bool> &visited) {
    if (visited[cur_pos]) return;
    visited[cur_pos] = true;
    dists[cur_pos] = cur_dist;
    for (auto next : edges[cur_pos]) {
        calc_dists(next, cur_dist + 1, edges, dists, visited);
    }
}

int main(void) {
    int N, u, v;
    cin >> N >> u >> v;

    vector<vector<int> > edges(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int A, B;
        cin >> A >> B;
        edges[A].push_back(B);
        edges[B].push_back(A);
    }

    map<int, int> dists_t, dists_a;
    vector<bool> visited_t(N + 1, false), visited_a(N + 1, false);
    calc_dists(u, 0, edges, dists_t, visited_t);
    calc_dists(v, 0, edges, dists_a, visited_a);

    int cand_dist = 0;
    for (int i = 1; i <= N; i++) {
        if (dists_a[i] > dists_t[i]) {
            chmax(cand_dist, dists_a[i]);
        }
    }

    cout << cand_dist - 1 << endl;

    return 0;
}
