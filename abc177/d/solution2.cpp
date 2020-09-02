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

// people[i] is a group number for i (or -1 if not assigned yet)
vector<int> people;

void dfs(const int cur_person, const int cur_group) {
    people[cur_person] = cur_group;
    for (auto next_person : edges[cur_person]) {
        if (people[next_person] == -1) {
            dfs(next_person, cur_group);
        }
    }
}

int main(void) {
    int N, M;
    cin >> N >> M;

    edges.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    people.resize(N, -1);

    int group_no = 0;
    for (int i = 0; i < N; i++) {
        if (people[i] == -1) {
            dfs(i, group_no);
            group_no++;
        }
    }

    vector<int> group_number(group_no, 0);
    for (int i = 0; i < N; i++) {
        group_number[people[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < group_no; i++) {
        chmax(ans, group_number[i]);
    }

    cout << ans << endl;

    return 0;
}
