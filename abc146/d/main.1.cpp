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

#define MAX_N 100000

class Edge {
    public:
        int to;
        int color;
        int index;
};

bool visited[MAX_N];

void color(const int cur_nd, int cur_color, const int color_variation, vector<vector<Edge> > &edges) {
    if (visited[cur_nd]) {
        return;
    }
    // cout << cur_nd << "," << cur_color << "," << color_variation << endl;
    visited[cur_nd] = true;
    for (int i = 0; i < (int) edges[cur_nd].size(); i++) {
        if (edges[cur_nd][i].index > MAX_N) continue;
        edges[cur_nd][i].color = ((cur_color++) % color_variation) + 1;
        // cout << edges[cur_nd][i].color << endl;
        color(edges[cur_nd][i].to, cur_color, color_variation, edges);
    }
}

/*
 * This is My wrong answer. 
 * This cannot correctly answer with test cases such as input4.txt.
 */
int main(void) {
    int N;
    cin >> N;

    vector<vector<Edge> > edges(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        edges[a - 1].push_back({b - 1, -1, i});
        edges[b - 1].push_back({a - 1, -1, MAX_N + 1});
    }

    int max_edge = -1;
    int nd_max_edge = -1;
    for (int i = 0; i < N; i++) {
        if ((int) edges[i].size() > max_edge) {
            max_edge = (int) edges[i].size();
            nd_max_edge = i;
        }
    }

    vector<bool> visited(N, false);
    color(nd_max_edge, 1, max_edge, edges);

    cout << max_edge << endl;

    vector<Edge> res;
    for (int i = 0; i < (int) edges.size(); i++) {
        for (int j = 0; j < (int) edges[i].size(); j++) {
            res.push_back(edges[i][j]);
        }
    }

    sort(res.begin(), res.end(), [](const Edge &a, const Edge &b) {
            return a.index < b.index;
    });

    for (int i = 0; i < N - 1; i++) {
        cout << res[i].color << endl;
    }

    return 0;
}
