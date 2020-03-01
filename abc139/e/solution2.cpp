#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

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

typedef pair<int, int> match;

map<match, int> match_to_id;
map<int, match> id_to_match;

match new_match(const int a, const int b) {
    assert(a != b);
    return { min(a, b), max(a, b) };
}

int get_id(match &x) {
    static int counter = 0;
    if (match_to_id.find(x) == match_to_id.end()) {
        match_to_id[x] = counter;
        id_to_match[counter] = x;
        counter++;
    }
    return match_to_id[x];
}

match get_match(int id) {
    match res = id_to_match[id];
    assert(res.first != 0 && res.second != 0);
    return res;
}

vector<vector<int>> graph;
vector<int> deps;

// solution based on bfs
int main(void) {
    int N;
    cin >> N;

    // nC2
    const int pair_num = N * (N - 1) / 2;
    graph.resize(pair_num);
    deps.resize(pair_num, 0);

    for (int i = 0; i < N; i++) {
        int prev = -1;
        int a = i + 1;
        for (int j = 0; j < N - 1; j++) {
            int b;
            cin >> b;
            auto match = new_match(a, b);
            auto id = get_id(match);
            if (prev != -1) {
                graph[prev].push_back(id);
                deps[id]++;
            }
            prev = id;
        }
    }

    // for (int i = 0; i < (int) graph.size(); i++) {
    //     match one = get_match(i);
    //     printf("(%d, %d): ", one.first, one.second);
    //     for (int j = 0; j < (int) graph[i].size(); j++) {
    //         match other = get_match(graph[i][j]);
    //         printf("(%d, %d) ", other.first, other.second);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    // for (int i = 0; i < N * (N - 1) / 2; i++) {
    //     printf("i: %d, deps[%d]: %d\n", i, i, deps[i]);
    // }
    // printf("\n");

    int ans = 0;
    int removed = 0;
    // {id, day}
    queue<pair<int, int>> q;

    for (int i = 0; i < pair_num; i++) {
        if (deps[i] == 0) {
            q.push({i, 1});
        }
    }

    while (!q.empty()) {
        auto id = q.front().first;
        auto day = q.front().second;
        q.pop();
        removed++;
        chmax(ans, day);

        for (auto other : graph[id]) {
            deps[other]--;
            if (deps[other] == 0) {
                q.push({other, day + 1});
            }
        }
    }

    if (removed == pair_num) {
        cout << ans << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}
