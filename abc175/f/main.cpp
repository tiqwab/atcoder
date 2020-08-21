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

const ll INF = LONG_LONG_MAX / 2;

vector<string> ss;
vector<int> cs;

// v_to_id[i][j] is an ID for a vertex which means the suffix of ss[i][j:]
vector<vector<int>> v_to_id;
map<int, pair<string, int>> id_to_v;

vector<vector<pair<int, ll>>> graph;

vector<ll> dists;

void solve(const int N, const int vn) {
    // {dist, vertex}
    typedef pair<ll, int> Elem;
    priority_queue<Elem, vector<Elem>, greater<Elem>> q;

    dists.resize(vn, INF);
    for (int i = 0; i < N; i++) {
        dists[v_to_id[i][0]] = cs[i];
        q.push(make_pair(cs[i], v_to_id[i][0]));
    }

    while (!q.empty()) {
        Elem elem = q.top();
        q.pop();
        ll cur_dist = elem.first;
        int cur_v = elem.second;
        if (cur_dist > dists[cur_v]) {
            continue;
        }

        for (auto edge : graph[cur_v]) {
            int next_v = edge.first;
            ll next_dist = cur_dist + edge.second;
            if (next_dist < dists[next_v]) {
                dists[next_v] = next_dist;
                q.push(make_pair(next_dist, next_v));
            }
        }
    }
}

// ref. https://www.youtube.com/watch?v=auQRcs5JMwE&feature=youtu.be
int main(void) {
    int N;
    cin >> N;

    ss.resize(N);
    cs.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> ss[i] >> cs[i];
    }
    for (int i = 0; i < N; i++) {
        string s = ss[i];
        reverse(s.begin(), s.end());
        ss.push_back(s);
        cs.push_back(cs[i]);
    }

    // assign ids
    int n = 1;
    v_to_id.resize(N * 2);
    for (int i = 0; i < N * 2; i++) {
        int l = (int) ss[i].size();
        v_to_id[i].resize(l);
        for (int j = 0; j < l; j++) {
            v_to_id[i][j] = n;
            id_to_v[n] = make_pair(ss[i], j);
            n++;
        }
    }

    // create graph
    graph.resize(n);
    for (int i = 0; i < N * 2; i++) {
        int l = (int) ss[i].size();
        for (int j = 0; j < l; j++) {
            int from = v_to_id[i][j];
            for (int ni = 0; ni < N * 2; ni++) {
                if (i / N == ni / N) {
                    continue;
                }

                int nl = (int) ss[ni].size();
                int l_covered = min(l - j, nl);
                if (ss[i].substr(j, l_covered) != ss[ni].substr(0, l_covered)) {
                    continue;
                }
#ifdef DEBUG
                printf("%d %s %s %s\n", l_covered, ss[i].c_str(), ss[i].substr(j, l_covered).c_str(), ss[ni].c_str());
#endif

                int to;
                if (nl > l_covered) {
                    to = v_to_id[ni][l_covered];
                } else if (l > j + l_covered) {
                    to = v_to_id[i][j + l_covered];
                } else {
                    to = 0;
                }
                graph[from].push_back(make_pair(to, cs[ni]));
            }
        }
    }

#ifdef DEBUG
    for (int i = 0; i < n; i++) {
        for (auto p : graph[i]) {
            printf("%d -> {to: %d, cost: %lld}\n", i, p.first, p.second);
            printf("  %s %d %s %d\n", id_to_v[i].first.c_str(), id_to_v[i].second,
                    id_to_v[p.first].first.c_str(), id_to_v[p.first].second);
        }
    }
#endif

    solve(N, n);

    ll ans = dists[0];
    for (int i = 0; i < N * 2; i++) {
        int l = (int) ss[i].size();
        for (int j = 0; j < l; j++) {
            string t = ss[i].substr(j);
            string u = t;
            reverse(u.begin(), u.end());
            if (t == u) { 
#ifdef DEBUG
                printf("i: %d, j: %d, %lld\n", i, j, dists[v_to_id[i][j]]);
#endif
                chmin(ans, dists[v_to_id[i][j]]);
            }
        }
    }

    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
