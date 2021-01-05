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

vector<pair<int, int>> orig_edges;
vector<vector<int>> edges;

vector<int> parent_for;

vector<ll> accs;
vector<ll> ans;

void assign_parent(const int cur) {
    for (auto child : edges[cur]) {
        if (parent_for[child] == -1) {
            parent_for[child] = cur;
            assign_parent(child);
        }
    }
}

void calc_ans(const int cur, const ll acc) {
    for (auto other : edges[cur]) {
        if (ans[other] == -1) {
            ans[other] = acc + accs[other];
            calc_ans(other, ans[other]);
        }
    }
}

int main(void) {
    int N;
    cin >> N;

    edges.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
        orig_edges.push_back(make_pair(a, b));
    }

    const int root = 0;

    parent_for.resize(N, -1);
    parent_for[root] = 0;
    assign_parent(root);

#ifdef DEBUG
    printf("parent_for: \n");
    for (int i = 0; i < N; i++) {
        cout << parent_for[i] << endl;
    }
    printf("\n");
#endif

    accs.resize(N, 0);

    int Q;
    cin >> Q;
    
    for (int i = 0; i < Q; i++) {
        int t, e, x, me, other;
        cin >> t >> e >> x;
        e--;

        if (t == 1) {
            me = orig_edges[e].first;
            other = orig_edges[e].second;
        } else {
            me = orig_edges[e].second;
            other = orig_edges[e].first;
        }

        if (parent_for[me] == other) {
            accs[me] += x;
        } else {
            accs[root] += x;
            accs[other] -= x;
        }
    }

#ifdef DEBUG
    printf("accs: \n");
    for (int i = 0; i < N; i++) {
        cout << accs[i] << endl;
    }
    printf("\n");
#endif

    ans.resize(N, -1);
    ans[root] = accs[root];
    calc_ans(root, ans[root]);

    for (int i = 0; i < N; i++) {
        printf("%lld\n", ans[i]);
    }

    return 0;
}
