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

const int MAX_L = 200000;

int main(void) {
    int N;
    cin >> N;

    vector<pair<int, int>> ranges;
    for (int i = 0; i < N; i++) {
        int l, r;
        cin >> l >> r;
        ranges.push_back(make_pair(l, r));
    }

    // for sentinel
    ranges.push_back(make_pair(MAX_L * 10, MAX_L * 10 + 1));

    sort(ranges.begin(), ranges.end(), [](auto &a, auto &b) {
        if (a.first != b.first) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });

#ifdef DEBUG
    for (int i = 0; i < N; i++) {
        printf("[%d, %d)\n", ranges[i].first, ranges[i].second);
    }
#endif

    auto current_range = ranges[0];
    vector<pair<int, int>> ans;

    for (int i = 1; i < (int) ranges.size(); i++) {
        auto range = ranges[i];

        if (current_range.second < range.first) {
            ans.push_back(current_range);
            current_range = range;
        } else {
            if (range.second <= current_range.second) {
                // do nothing
            } else {
                current_range.second = range.second;
            }
        }
    }

    for (auto range : ans) {
        printf("%d %d\n", range.first, range.second);
    }

    return 0;
}
