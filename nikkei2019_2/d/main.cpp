#include <algorithm>
#include <iostream>
#include <queue>

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

class Edge {
    public:
        int to;
        int c;

        friend ostream& operator<<(ostream &os, const Edge &a) {
            os << "{to=" << a.to + 1 << ", c=" << a.c << "}";
            return os;
        }
};

class Elem {
    public:
        int i;
        ll distance;

        bool operator < (const Elem &other) const {
            return distance < other.distance;
        }

        bool operator > (const Elem &other) const {
            return distance > other.distance;
        }
};

const int MAX_N = 100000;
const int MAX_M = 100000;

int n;
int m;
int edge_num;
vector<Edge> adjlist[MAX_N];
priority_queue<Elem, vector<Elem>, greater<Elem> > q;

void print_edges() {
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ": ";
        for (auto edge : adjlist[i]) {
            cout << edge << ",";
        }
        cout << endl;
    }
}

int main(void) {
    cin >> n;
    cin >> m;

    edge_num = m + n - 1;

    for (int i = 0; i < n - 1; i++) {
        adjlist[i + 1].push_back({i, 0});
    }

    for (int i = 0; i < m; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        adjlist[l - 1].push_back({r - 1, c});
    }

    // print_edges();

    vector<ll> d(n, LONG_LONG_MAX / 2);

    d[0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        Elem elem = q.top();
        q.pop();

        if (d[elem.i] < elem.distance) {
            continue;
        }

        for (auto edge : adjlist[elem.i]) {
            if (d[elem.i] + edge.c < d[edge.to]) {
                d[edge.to] = d[elem.i] + edge.c;
                q.push({edge.to, d[edge.to]});
            }
        }

        // for (int i = 0; i < n; i++) {
        //     cout << d[i] << ",";
        // }
        // cout << endl;
    }

    if (d[n - 1] == LONG_LONG_MAX / 2) {
        printf("%d\n", -1);
    } else {
        printf("%lld\n", d[n - 1]);
    }

    return 0;
}
