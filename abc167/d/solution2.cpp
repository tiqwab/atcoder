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
int loop_start;
int linear_size;
int loop_size;
vector<int> visited;
vector<int> ords;

void detect_cycle(int cur, int k) {
    if (visited[cur] >= 0) {
        loop_start = cur;
        linear_size = visited[cur];
        loop_size = k - visited[cur];
        return;
    }

    visited[cur] = k;
    k++;
    ords.push_back(cur);
    detect_cycle(edges[cur][0], k);
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
        edges[i].push_back(t);
    }

    visited.resize(N, -1);
    detect_cycle(0, 0);

    if (linear_size >= K) {
        cout << ords[K] + 1 << endl;
    } else {
        cout << ords[linear_size + ((K - linear_size) % loop_size)] + 1 << endl;
    }

    return 0;
}
