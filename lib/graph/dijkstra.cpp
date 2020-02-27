#include <iostream>
#include <queue>

#include <limits.h>

using namespace std;

typedef long long ll;

const ll INF = LONG_LONG_MAX / 2;

class Elem {
    public:
        int vertex;
        ll distance;

        bool operator < (const Elem &other) const {
            return distance < other.distance;
        }

        bool operator > (const Elem &other) const {
            return distance > other.distance;
        }
};

typedef vector<vector<Elem>> Edges;
Edges edges;

/*
 * ref. https://ja.wikipedia.org/wiki/%E3%83%80%E3%82%A4%E3%82%AF%E3%82%B9%E3%83%88%E3%83%A9%E6%B3%95
 *
 * usage:
 *
 * int main(void) {
 *     int V, E, start; // vertices, edges, start
 *     cin >> V >> E >> start;
 *     Graph g(V, INF, edges);
 *     g.dijkstra(start);
 *     // do something with d.d_list and d.prev_list
 * }
 */
class Graph {
    public:
        const int V; // num of vertices
        const ll INF;
        const Edges &edges;
        vector<int> prev_list; // previous vertex on the shortest path from start (calculated after dijkstra())
        vector<ll> d_list; // distance from start (calculated after dijkstra())

        Graph(int v, ll inf, Edges &edges) : V(v), INF(inf), edges(edges) {
        }

        void dijkstra(const int start) {
            priority_queue<Elem, vector<Elem>, greater<Elem>> q;

            init();
            d_list[start] = 0;
            for (int i = 0; i < V; i++) {
                q.push({i, d_list[i]});
            }

            while (q.size() > 0) {
                Elem elem = q.top();
                q.pop();

                for (int i = 0; i < (int) edges[elem.vertex].size(); i++) {
                    Elem next = edges[elem.vertex][i];
                    ll alt = d_list[elem.vertex] + next.distance;
                    if (d_list[next.vertex] > alt) {
                        d_list[next.vertex] = alt;
                        prev_list[next.vertex] = elem.vertex;

                        Elem e;
                        e.vertex = next.vertex;
                        e.distance = d_list[next.vertex];
                        q.push(e);
                    }
                }
            }
        }

    private:
        void init() {
            prev_list.clear();
            prev_list.resize(V, -1);

            d_list.clear();
            d_list.resize(V, INF);
        }
};

// ref. http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp
int main(void) {
    int V, E, r; // vertices, edges, start
    cin >> V >> E >> r;

    edges.resize(V, vector<Elem>());

    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        edges[s].push_back({t, d});
    }

    Graph g(V, INF, edges);
    g.dijkstra(r);

    for (int i = 0; i < V; i++) {
        if (g.d_list[i] != INF) {
            cout << g.d_list[i] << endl;
        } else {
            cout << "INF" << endl;
        }
    }

    return 0;
}
