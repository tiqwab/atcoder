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

bool solve(const vector<pair<int, int>> &areas, const int N) {
    auto f = [](const pair<int, int>& one, const pair<int, int>& other) {
        if (one.second != other.second) {
            return one.second > other.second;
        } else {
            return one.first > other.first;
        }
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(f)> q(f);

    int pos = 0;
    int idx_areas = 0;
    pos = areas[idx_areas].first;

    while (idx_areas < N || !q.empty()) {
        while (idx_areas < N && areas[idx_areas].first == pos) {
            q.push(areas[idx_areas]);
            idx_areas++;
        }
        if (q.empty()) {
            if (idx_areas < N) {
                pos = areas[idx_areas].first;
            }
        } else {
            pair<int, int> area = q.top();
            if (area.first <= pos && pos <= area.second) {
                q.pop();
                pos += 1;
            } else {
                return false;
            }
        }
    }

    return true;
}

int main(void) {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;

        vector<pair<int, int>> areas;
        for (int j = 0; j < N; j++) {
            int l, r;
            cin >> l >> r;
            areas.push_back(make_pair(l, r));
        }

        sort(areas.begin(), areas.end());

        if (solve(areas, N)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
