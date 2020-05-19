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
vector<int> shirube;

void bfs() {
    // {cur, prev}
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto &nv : edges[cur]) {
            if (shirube[nv] < 0) {
                shirube[nv] = cur;
                q.push(nv);
            }
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

    shirube.resize(N, -1);
    shirube[0] = 0;

    bfs();

    cout << "Yes" << endl;
    for (int i = 1; i < N; i++) {
        cout << shirube[i] + 1 << endl;
    }

    return 0;
}
