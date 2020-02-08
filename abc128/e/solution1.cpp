#include <algorithm>
#include <iostream>
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

const int INF = INT_MAX / 2;

class Construction {
    public:
        // cannot pass x between [s, t].
        int s;
        int t;
        int x;
};

vector<Construction> constructions;
vector<int> D;
vector<int> ans;

void solve(const int N, const int Q) {
    // keys of set in c++ are sorted
    set<pair<int, int>> people;
    for (int i = 0; i < Q; i++) {
        people.insert({D[i], i});
    }

    for (int i = 0; i < N; i++) {
        Construction cons = constructions[i];
        int s = max(0, cons.s - cons.x);
        int t = max(0, cons.t - cons.x);
        auto p1 = people.lower_bound({s, -1});
        auto p2 = people.upper_bound({t, INF});

        set<pair<int, int>> should_delete;
        for (auto p = p1; p != p2; p++) {
            chmin(ans[p->second], cons.x);
            should_delete.insert(*p);
        }
        for (auto &p : should_delete) {
            people.erase(p);
        }
    }
}

// based on the solution explained in the video (https://www.youtube.com/watch?v=m-Nov1EvGoc)
int main(void) {
    int N, Q;
    cin >> N >> Q;

    constructions.resize(N);
    for (int i = 0; i < N; i++) {
        int s, t, x;
        cin >> s >> t >> x;
        t--;
        constructions[i].s = s;
        constructions[i].t = t;
        constructions[i].x = x;
    }
    sort(constructions.begin(), constructions.end(), [](const auto &a, const auto &b) {
            return a.x < b.x;
            });

    D.resize(Q);
    for (int i = 0; i < Q; i++) {
        cin >> D[i];
    }

    ans.resize(Q, INF);

    solve(N, Q);

    for (int i = 0; i < Q; i++) {
        if (ans[i] == INF) {
            cout << "-1" << endl;
        } else {
            cout << ans[i] << endl;
        }
    }

    return 0;
}
