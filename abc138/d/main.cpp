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

const int MAX_N = 2 * 100000;

int node[MAX_N];
int answer[MAX_N];
bool visited[MAX_N];

void f(const int cur_nd, int acc, const vector<vector<int> > &edge) {
    if (visited[cur_nd]) {
        return;
    }
    visited[cur_nd] = true;
    acc += node[cur_nd];
    answer[cur_nd] = acc;
    for (int i = 0; i < (int) edge[cur_nd].size(); i++) {
        f(edge[cur_nd][i], acc, edge);
    }
}

int main(void) {
    int N, Q;
    cin >> N >> Q;

    vector<vector<int> > edge(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        edge[a - 1].push_back(b - 1);
        edge[b - 1].push_back(a - 1);
    }

    for (int q = 0; q < Q; q++) {
        int p, x;
        cin >> p >> x;
        node[p - 1] += x;
    }

    f(0, 0, edge);

    cout << answer[0];
    for (int i = 1; i < N; i++) {
        cout << " " << answer[i];
    }
    cout << endl;

    return 0;
}
