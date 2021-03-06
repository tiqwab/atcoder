#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

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

const int INF = 1001001001;

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
 *     Graph g(V, E, edges);
 *     g.dijkstra(start);
 *     // do something with d.d_list and d.prev_list
 * }
 */
class Graph {
    public:
        const int V; // num of vertices
        const int INF;
        const Edges &edges;
        vector<int> prev_list; // previous vertex on the shortest path from start (calculated after dijkstra())
        vector<ll> d_list; // distance from start (calculated after dijkstra())

        Graph(int v, int inf, Edges &edges) : V(v), INF(inf), edges(edges) {
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

int main(void) {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> maze(H, vector<char>(W, '.'));
    for (int i = 0; i < H; i++) {
        string S;
        cin >> S;
        for (int j = 0; j < W; j++) {
            if (S[j] == '#') {
                maze[i][j] = '#';
            }
        }
    }

#define POS(x, y) ((x) * W + y)

    const int N = H * W;
    edges.resize(N, vector<Elem>());
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            // up
            if (i >= 1 && maze[i - 1][j] != '#') {
                edges[POS(i, j)].push_back({POS(i - 1, j), 1});
            }
            // right
            if (j < W - 1 && maze[i][j + 1] != '#') {
                edges[POS(i, j)].push_back({POS(i, j + 1), 1});
            }
            // down
            if (i < H - 1 && maze[i + 1][j] != '#') {
                edges[POS(i, j)].push_back({POS(i + 1, j), 1});
            }
            // left
            if (j >= 1 && maze[i][j - 1] != '#') {
                edges[POS(i, j)].push_back({POS(i, j - 1), 1});
            }
        }
    }

    Graph g(N, INF, edges);

    ll max = 0;
    for (int i = 0; i < N; i++) {
        if (maze[i / W][i % W] == '#') continue;
        g.dijkstra(i);
        for (int i = 0; i < N; i++) {
            if (g.d_list[i] != INF) {
                chmax(max, g.d_list[i]);
            }
        }
    }

    cout << max << endl;

    return 0;
}
