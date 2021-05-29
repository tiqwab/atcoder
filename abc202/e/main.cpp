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

// visited[i] = {entrance time, leave time} for vertex i
vector<pair<int, int>> visited;

// deps_to_entrance[i] is entrance times of vertices whose depth is i
// vector is ascending ordered
map<int, vector<int>> deps_to_entrance;

void visit(const int cur_v, int &cur_time, const int depth) {
    visited[cur_v].first = cur_time;
    deps_to_entrance[depth].push_back(cur_time);
    cur_time += 1;
    for (auto to : edges[cur_v]) {
        visit(to, cur_time, depth + 1);
        cur_time += 1;
    }
    visited[cur_v].second = cur_time;
}

int main(void) {
    int N;
    cin >> N;

    edges.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int p;
        cin >> p;
        p--;
        edges[p].push_back(i + 1);
    }

    {
        visited.resize(N);
        int time = 0;
        visit(0, time, 0);
    }

#ifdef DEBUG
    printf("visited: \n");
    for (int i = 0; i < N; i++) {
        printf("  %d: %d, %d\n", i, visited[i].first, visited[i].second);
    }
#endif

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int U, D;
        cin >> U >> D;
        U--;
        int entrance_time_of_u = visited[U].first;
        int leave_time_of_u = visited[U].second;
        auto &times = deps_to_entrance[D];
        auto it_entrance = lower_bound(times.begin(), times.end(), entrance_time_of_u);
        auto it_leave = lower_bound(times.begin(), times.end(), leave_time_of_u);
        printf("%ld\n", distance(it_entrance, it_leave));
    }

    return 0;
}
