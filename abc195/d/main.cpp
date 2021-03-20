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

// {weight, value}
vector<pair<int, int>> items;
vector<int> all_boxes;

int solve(const int N, vector<int> &boxes) {
    auto f = [](const pair<int, int>& one, const pair<int, int>& other) {
        if (one.second != other.second) {
            return one.second < other.second;
        } else {
            return one.first < other.first;
        }
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(f)> q(f);

    sort(boxes.begin(), boxes.end());

    int ans = 0;
    int idx_item = 0;

    for (auto &box : boxes) {
        while (idx_item < N && items[idx_item].first <= box) {
            q.push(items[idx_item]);
            idx_item++;
        }
        // printf("box: %d, idx_item: %d\n", box, idx_item);
        if (((int) q.size()) > 0) {
            auto item = q.top();
            q.pop();
            ans += item.second;
        }
    }

    return ans;
}

int main(void) {
    int N, M, Q;
    cin >> N >> M >> Q;

    items.resize(N);
    for (int i = 0; i < N; i++) {
        int w, v;
        cin >> w >> v;
        items[i] = make_pair(w, v);
    }
    sort(items.begin(), items.end());

    all_boxes.resize(M);
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        all_boxes[i] = x;
    }

    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;
        L--;
        R--;

        vector<int> boxes;
        for (int j = 0; j < M; j++) {
            if (j < L || R < j) {
                boxes.push_back(all_boxes[j]);
            }
        }

        cout << solve(N, boxes) << endl;
    }

    return 0;
}
