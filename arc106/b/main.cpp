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

vector<int> as;
vector<int> bs;

vector<vector<int>> edges;
vector<int> group;

void visit(const int cur, const int group_no, vector<int> &acc, const int N, const int M) {
    if (group[cur] != -1) {
        return;
    }

    group[cur] = group_no;
    acc.push_back(cur);

    for (auto next : edges[cur]) {
        if (group[next] == -1) {
            visit(next, group_no, acc, N, M);
        }
    }
}

bool check(const vector<int> &members) {
    ll sum_a = 0;
    ll sum_b = 0;

    for (auto x : members) {
        sum_a += as[x];
        sum_b += bs[x];
    }

    return sum_a == sum_b;
}

int main(void) {
    int N, M;
    cin >> N >> M;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    bs.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> bs[i];
    }

    edges.resize(N);
    for (int i = 0; i < M; i++) {
        int c, d;
        cin >> c >> d;
        c--;
        d--;
        edges[c].push_back(d);
        edges[d].push_back(c);
    }

    group.resize(N, -1);

    bool ok = true;
    int group_no = 0;
    for (int i = 0; i < N; i++) {
        if (group[i] == -1) {
            vector<int> members;
            visit(i, group_no, members, N, M);
            group_no++;
            if (!check(members)) {
                ok = false;
                break;
            }
        }
    }

    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
