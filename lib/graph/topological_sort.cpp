#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

/*
 * 'from' depends 'to', which means 'to' must be done before 'from'.
 */
class Edge {
    public:
        int from;
        int to;
        int cost;
};

enum VisitStatus {
    NOT_VISITED,
    VISITING,
    VISITED
};

void print_edges(const vector<vector<Edge> > &edges) {
    for (int i = 0; i < (int) edges.size(); i++) {
        cout << i << ": ";
        for (int j = 0; j < (int) edges[i].size(); j++) {
            cout << edges[i][j].to << " ";
        }
        cout << endl;
    }
}

const int MAX_V = 10000;
const int MAX_E = 100000;

/*
 * edges: edges represented by adjacent list
 * n: number of vertices
 * v: current verticle
 * sorted: sorted vertices
 */
static bool do_topological_sort(const vector<vector<Edge> > &edges, const int n, const int v,
        vector<VisitStatus> &visited, vector<int> &sorted) {
    for (int i = 0; i < (int) edges[v].size(); i++) {
        const Edge edge = edges[v][i];
        if (visited[edge.to] == VISITING) {
            // detect cyclization
            return false;
        } else if (visited[edge.to] == NOT_VISITED) {
            visited[edge.to] = VISITING;
            if (!do_topological_sort(edges, n, edge.to, visited, sorted)) {
                return false;
            }
        }
    }

    sorted.push_back(v);
    visited[v] = VISITED;
    return true;
}

/*
 * Return false if the given graph is not DAG.
 * Result is stored in sorted.
 *
 * Assume that ids of vertices starts from 0.
 */
bool topological_sort(const vector<vector<Edge> > &edges, const int n,
        vector<VisitStatus> &visited, vector<int> &sorted) {
    assert((int) edges.size() == n);
    assert((int) visited.size() == n);

    for (int i = 0; i < n; i++) {
        if (visited[i] != VISITED) {
            visited[i] = VISITING;
            if (!do_topological_sort(edges, n, i, visited, sorted)) {
                return false;
            }
        }
    }

    return true;
}

/*
 * ref. http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
 */
int main(void) {
    int v, e;
    cin >> v >> e;

    vector<vector<Edge> > edges(v);
    vector<VisitStatus> visited(v);

    for (int i = 0; i < e; i++) {
        int s, t, cost;
        cin >> s >> t;
        cost = 1;
        edges[t].push_back({t, s, cost});
    }

    // print_edges(edges);

    vector<int> answer;
    if (!topological_sort(edges, v, visited, answer)) {
        cerr << "Failed to perform topological sort due to cyclization" << endl;
        return 1;
    }

    for (int i = 0; i < (int) answer.size(); i++) {
        cout << answer[i] << endl;
    }

    return 0;
}
