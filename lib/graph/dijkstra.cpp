#include <iostream>
#include <queue>

/*
 * ref. https://ja.wikipedia.org/wiki/%E3%83%80%E3%82%A4%E3%82%AF%E3%82%B9%E3%83%88%E3%83%A9%E6%B3%95
 */

using namespace std;

#define MAX_V 100000
#define INF 1000000001

typedef long long ll;
typedef int PrevList[MAX_V];
typedef ll DistanceList[MAX_V];

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

typedef vector<vector<Elem> > Edges;

typedef priority_queue<Elem, vector<Elem>, greater<Elem> > PriorityQueue;

/*
 * n: size of vertices (assume that names of vertices are 0, 1, ..., n-1)
 * start: start vertex
 */
void dijkstra(const int n, const int start, const Edges &edges,
        PrevList &prev_list, DistanceList &d_list, PriorityQueue &queue) {
    // Initialization
    for (int i = 0; i < n; i++) {
        if (i == start) {
            d_list[i] = 0;
        } else {
            d_list[i] = INF;
        }

        prev_list[i] = -1;

        Elem elem;
        elem.vertex = i;
        elem.distance = d_list[i];
        queue.push(elem);
    }

    while (queue.size() > 0) {
        Elem elem = queue.top();
        queue.pop();

        for (int i = 0; i < edges[elem.vertex].size(); i++) {
            Elem next = edges[elem.vertex][i];
            ll alt = d_list[elem.vertex] + next.distance;
            if (d_list[next.vertex] > alt) {
                d_list[next.vertex] = alt;
                prev_list[next.vertex] = elem.vertex;

                Elem e;
                e.vertex = next.vertex;
                e.distance = d_list[next.vertex];
                queue.push(e);
            }
        }
    }
}

Edges edges;
PrevList prev_list;
DistanceList d_list;

// ref. http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp
int main(void) {
    PriorityQueue q;

    int v, e, r;

    cin >> v >> e >> r;

    for (int i = 0; i < v; i++) {
        edges.push_back(vector<Elem>());
    }

    for (int i = 0; i < e; i++) {
        int s, t, d;
        Elem e;
        cin >> s >> t >> d;

        e.vertex = t;
        e.distance = d;
        edges[s].push_back(e);
    }

    dijkstra(v, r, edges, prev_list, d_list, q);

    for (int i = 0; i < v; i++) {
        if (d_list[i] != INF) {
            cout << d_list[i] << endl;
        } else {
            cout << "INF" << endl;
        }
    }

    return 0;
}
