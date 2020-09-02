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

const int INF = INT_MAX / 2;

vector<pair<int, int>> walls;

// ref. https://www.youtube.com/watch?v=D6dr2CrEgns
int main(void) {
    int H, W;
    cin >> H >> W;

    walls.resize(H);
    for (int i = 0; i < H; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        walls[i] = make_pair(a, b);
    }

    map<int, int> pos_to_start;
    multiset<int> dist;
    for (int i = 0; i < W; i++) {
        pos_to_start[i] = i;
        dist.insert(0);
    }

    for (int h = 0; h < H; h++) {
        const int l = walls[h].first;
        const int r = walls[h].second;

        auto it = pos_to_start.lower_bound(l);
        int most_right_start = -1;
        while (it != pos_to_start.end() && it->first <= r) {
            if (r < W) {
                chmax(most_right_start, it->second);
            }
            dist.erase(dist.find(it->first - it->second));
            it = pos_to_start.erase(it);
        }
        if (most_right_start != -1) {
            pos_to_start[r] = most_right_start;
            dist.insert(r - most_right_start);
        }

        if ((int) dist.size() > 0) {
            cout << *(dist.begin()) + (h + 1) << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
