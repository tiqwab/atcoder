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
        int from;
        int to;
        int index;
};

map<pair<int, int>, int> colors;

void color(const int cur_nd, int cur_color, const int color_variation, vector<vector<Edge> > &edges) {
    for (int i = 0; i < (int) edges[cur_nd].size(); i++) {
        int other = edges[cur_nd][i].to;
        if (colors.find(make_pair(other, cur_nd)) != colors.end()) {
            colors[make_pair(cur_nd, other)] = colors[make_pair(other, cur_nd)];
        } else {
            colors[make_pair(cur_nd, other)] = ((cur_color++) % color_variation) + 1;
            color(edges[cur_nd][i].to, cur_color, color_variation, edges);
        }
    }
}

int main(void) {
    int N;
    cin >> N;

    vector<vector<Edge> > edges(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        edges[a - 1].push_back({a - 1, b - 1, i});
        edges[b - 1].push_back({b - 1, a - 1, MAX_N + 1});
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
        cout << colors[make_pair(res[i].from, res[i].to)] << endl;
    }

    return 0;
}
