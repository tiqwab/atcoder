#include <iostream>
#include <vector>

/*
 * ref. https://ja.wikipedia.org/wiki/%E3%83%99%E3%83%AB%E3%83%9E%E3%83%B3%E2%80%93%E3%83%95%E3%82%A9%E3%83%BC%E3%83%89%E6%B3%95
 * ref. https://dai1741.github.io/maximum-algo-2012/docs/shortest-path/
 */

using namespace std;

#define MAX_V 100000
#define INF 1000000001

typedef long long ll;
typedef int PrevList[MAX_V];
typedef ll DistanceList[MAX_V];

class Edge {
    public:
        int start;
        int end;
        ll distance;
};

typedef vector<Edge> Edges;

/*
 * n: size of vertices (assume that names of vertices are 0, 1, ..., n-1)
 * start: start vertex
 */
void bellman_ford(const int n, const int start, const Edges &edges,
        PrevList &prev_list, DistanceList &d_list) {
    // Initialization
    for (int i = 0; i < n; i++) {
        if (i == start) {
            d_list[i] = 0;
        } else {
            d_list[i] = INF;
        }
        prev_list[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        for (size_t j = 0; j < edges.size(); j++) {
            Edge edge = edges[j];
            ll alt = d_list[edge.start] + edge.distance;
            if (alt < d_list[edge.end]) {
                d_list[edge.end] = alt;
                prev_list[edge.end] = edge.start;
            }
        }
    }

    // Check existence of a negative-weight cycle
    for (size_t i = 0; i < edges.size(); i++) {
        Edge edge = edges[i];
        if (d_list[edge.start] + edge.distance < d_list[edge.end]) {
            cerr << "Graph contains a negative-weight cycle" << endl;
        }
    }
}

Edges edges;
PrevList prev_list;
DistanceList d_list;

// ref. http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp
int main(void) {
    int v, e, r;

    cin >> v >> e >> r;

    for (int i = 0; i < e; i++) {
        int s, t, d;
        Edge e;
        cin >> s >> t >> d;

        e.start = s;
        e.end = t;
        e.distance = d;
        edges.push_back(e);
    }

    bellman_ford(v, r, edges, prev_list, d_list);

    for (int i = 0; i < v; i++) {
        if (d_list[i] != INF) {
            cout << d_list[i] << endl;
        } else {
            cout << "INF" << endl;
        }
    }

    return 0;
}
