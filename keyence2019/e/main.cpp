#include <algorithm>
#include <iostream>
#include <queue>
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

// ref. arihon 3-3
// E: type of data, R: type of query result
template<typename E, typename R>
class SegmentTree {
    public:
        SegmentTree(const int _n, const E inf, R (*f)(E, E)): f(f), inf(inf) {
            n = 1;
            while (n < _n) n *= 2;
            data.resize(2 * n, inf);
        }

        // update data[k] with a
        // time complexity: O(n)
        void update(int k, E a) {
            k += n - 1;
            data[k] = a;
            while (k > 0) {
                k = (k - 1) / 2;
                data[k] = (*f)(data[k * 2 + 1], data[k * 2 + 2]);
            }
        }

        // query value from [a, b)
        // // time complexity: O(n)
        R query(int a, int b) {
            return query(a, b, 0, 0, n);
        }

    private:
        int n;
        R (*f)(E, E);
        const E inf;
        vector<E> data;

        R query(int a, int b, int k, int l, int r) {
            // if [a, b) intersect [l, r) = empty
            if (r <= a || b <= l) {
                return inf;
            }

            // if [a, b) includes [l, r)
            if (a <= l && r <= b) {
                return data[k];
            } else {
                R vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
                R vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
                return (*f)(vl, vr);
            }
        }
};

// descending order base on costs
auto compare = [](const pair<int, ll> &x, const pair<int, ll> &y) {
    return x.second > y.second;
};
typedef priority_queue<pair<int, ll>, vector<pair<int, ll>>, decltype(compare)> PriorityQueue;

// {city, cost}
vector<vector<pair<int, ll>>> edges;
vector<bool> visited;

ll solve(PriorityQueue q) {
    ll acc = 0;

    while (!q.empty()) {
        pair<int, ll> edge = q.top();
        int dest = edge.first;
        ll cost = edge.second;
        q.pop();
        if (visited[dest]) continue;

        visited[dest] = true;
        acc += cost;
        for (int i = 0; i < (int) edges[dest].size(); i++) {
            q.push(edges[dest][i]);
        }
    }

    return acc;
}

// {city, cost}
vector<pair<int, ll>> A;

// ref. https://betrue12.hateblo.jp/entry/2019/01/14/023707
int main(void) {
    ll N, D;
    cin >> N >> D;

    A.resize(N);
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        A[i].first = i;
        A[i].second = a;
    }
    sort(A.begin(), A.end(), [](const pair<int, ll> &x, const pair<int, ll> &y) {
            return x.second < y.second;
            });

    // {city, cost}
    auto f = [](pair<int, ll> x, pair<int, ll> y) {
        if (x.second < y.second) {
            return x;
        } else {
            return y;
        }
    };
    pair<int, ll> inf = {-1, INF};
    SegmentTree<pair<int, ll>, pair<int, ll>> *st_left =
        new SegmentTree<pair<int, ll>, pair<int, ll>>(N, inf, f);
    SegmentTree<pair<int, ll>, pair<int, ll>> *st_right =
        new SegmentTree<pair<int, ll>, pair<int, ll>>(N, inf, f);

    edges.resize(N);
    for (int i = 0; i < (int) A.size(); i++) {
        auto p = st_left->query(0, A[i].first);
        if (p != inf) {
            edges[A[i].first].push_back({p.first, p.second + A[i].second - (N - A[i].first) * D});
            edges[p.first].push_back({A[i].first, p.second + A[i].second - (N - A[i].first) * D});
        }

        p = st_right->query(A[i].first + 1, N);
        if (p != inf) {
            edges[A[i].first].push_back({p.first, p.second + A[i].second - A[i].first * D});
            edges[p.first].push_back({A[i].first, p.second + A[i].second - A[i].first * D});
        }

        st_left->update(A[i].first, {A[i].first, A[i].second + (N - A[i].first) * D});
        st_right->update(A[i].first, {A[i].first, A[i].second + A[i].first * D});
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < (int) edges[i].size(); j++) {
    //         printf("%d -%d-> %d\n", i, edges[i][j].second, edges[i][j].first);
    //     }
    // }

    visited.resize(N, false);
    visited[0] = true;

    PriorityQueue q(compare);
    for (int i = 0; i < (int) edges[0].size(); i++) {
        q.push(edges[0][i]);
    }

    cout << solve(q) << endl;

    delete st_left;
    delete st_right;
    return 0;
}
