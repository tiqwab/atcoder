#include <algorithm>
#include <iostream>
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

vector<vector<int>> friends;
vector<vector<int>> blocks;

void solve(const int cur, const int current_turn, vector<int> &acc, vector<int> &visited, const int N) {
    if (visited[cur] > 0) return;
    visited[cur] = current_turn;
    acc.push_back(cur);
    for (auto &next : friends[cur]) {
        if (visited[next] == 0) {
            solve(next, current_turn, acc, visited, N);
        }
    }
}

int main(void) {
    int N, M, K;
    cin >> N >> M >> K;

    friends.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    blocks.resize(N);
    for (int i = 0; i < K; i++) {
        int c, d;
        cin >> c >> d;
        c--;
        d--;
        blocks[c].push_back(d);
        blocks[d].push_back(c);
    }

    vector<int> ans(N, 0);
    vector<int> visited(N, 0);
    int current_turn = 0;
    for (int i = 0; i < N; i++) {
        if (visited[i] == 0) {
            current_turn++;
            vector<int> visited_vs;
            solve(i, current_turn, visited_vs, visited, N);
            for (auto &v : visited_vs) {
                ans[v] = (int) visited_vs.size();
            }
        }
    }

    for (int i = 0; i < N; i++) {
        ans[i]--; // remove myself
        ans[i] -= friends[i].size(); // already friends
        for (auto &v : blocks[i]) {
            if (visited[v] == visited[i]) {
                ans[i]--;
            }
        }
    }

    cout << ans[0];
    for (int i = 1; i < N; i++) {
        cout << " " << ans[i];
    }
    cout << endl;

    return 0;
}
