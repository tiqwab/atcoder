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

const int MAX_N = 100000;
const int INF = INT_MAX / 2;

vector<vector<int>> edges;

auto eval_f = [](const pair<int, bool>& one, const pair<int, bool>& other) {
    if (one.second && other.second) {
        return one.first < other.first;
    } else if (one.second && !other.second) {
        // choose other if profit >= 0
        return other.first >= 0;
    } else if (!one.second && other.second) {
        // choose one if profit >= 0
        return !(one.first >= 0);
    } else {
        return one.first < other.first;
    }
};

// cur_node 以下の部分木について cur_node のコインを得た人間にとっての profit を返す。
// {profit, nodes_cnt}
pair<int, int> calc_for(const int cur_node) {
    priority_queue<pair<int, bool>, vector<pair<int, bool>>, decltype(eval_f)> q(eval_f);

    int profit = 1;
    int nodes_cnt = 1;
    bool teban = false; // 自分は cur_node のコインを取ったので相手から始まる

    for (auto to : edges[cur_node]) {
        pair<int, int> res = calc_for(to);
        q.push(make_pair(-1 * res.first, res.second % 2 == 1));
        nodes_cnt += res.second;
    }

    while (!q.empty()) {
        pair<int, bool> p = q.top();
        q.pop();
        if (teban) {
            profit += p.first;
        } else {
            profit -= p.first;
        }
        if (p.second) {
            teban = !teban;
        }
    }

#ifdef DEBUG
    printf("cur_node: %d, profit: %d, is_changed: %d\n", cur_node, profit, nodes_cnt % 2 == 1);
#endif
    return make_pair(profit, nodes_cnt % 2 == 1);
}

int main(void) {
    int N;
    cin >> N;

    edges.resize(N);

    for (int i = 1; i < N; i++) {
        int p;
        cin >> p;
        p--;
        edges[p].push_back(i);
    }

    pair<int, int> res = calc_for(0);
    cout << (N + res.first) / 2 << endl;

    return 0;
}
