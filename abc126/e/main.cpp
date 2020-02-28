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

vector<vector<int>> edges;
vector<bool> visited;

void solve(const int cur) {
    visited[cur] = true;

    for (auto &next : edges[cur]) {
        if (visited[next]) {
            continue;
        }
        solve(next);
    }
}

int main(void) {
    int N, M;
    cin >> N >> M;

    edges.resize(N);
    for (int i = 0; i < M; i++) {
        int X, Y, Z;
        cin >> X >> Y >> Z;
        X--;
        Y--;
        edges[X].push_back(Y);
        edges[Y].push_back(X);
    }

    visited.resize(N, false);
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            count++;
            solve(i);
        }
    }

    cout << count << endl;

    return 0;
}
