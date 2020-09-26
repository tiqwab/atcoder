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

int INF = INT_MAX / 2;

vector<pair<int, int>> ps;

// My first wrong answer.
// It cannot solve a problem like:
// 7
// 1 4
// 1 5
// 2 2
// 2 8
// 4 1
// 4 7
// 4 9
//
// (actual answer is 9, but it emits 8.)
int main(void) {
    int N;
    cin >> N;

    ps.resize(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        ps[i] = make_pair(x, y);
    }

    vector<pair<int, int>> cands;

    {
        int idx = -1;
        int min_x = INF;
        for (int i = 0; i < N; i++) {
            if (ps[i].first < min_x) {
                idx = i;
                min_x = ps[i].first;
            }
        }
        cands.push_back(ps[idx]);
    }

    {
        int idx = -1;
        int max_x = -INF;
        for (int i = 0; i < N; i++) {
            if (ps[i].first > max_x) {
                idx = i;
                max_x = ps[i].first;
            }
        }
        cands.push_back(ps[idx]);
    }

    {
        int idx = -1;
        int min_y = INF;
        for (int i = 0; i < N; i++) {
            if (ps[i].second < min_y) {
                idx = i;
                min_y = ps[i].second;
            }
        }
        cands.push_back(ps[idx]);
    }

    {
        int idx = -1;
        int max_y = -INF;
        for (int i = 0; i < N; i++) {
            if (ps[i].second > max_y) {
                idx = i;
                max_y = ps[i].second;
            }
        }
        cands.push_back(ps[idx]);
    }

#ifdef DEBUG
    for (int i = 0; i < (int) cands.size(); i++) {
        printf("(%d, %d)\n", cands[i].first, cands[i].second);
    }
#endif

    int ans = 0;
    for (int i = 0; i < (int) cands.size(); i++) {
        for (int j = 0; j < (int) cands.size(); j++) {
            chmax(ans, abs(cands[i].first - cands[j].first) + abs(cands[i].second - cands[j].second));
        }
    }
    cout << ans << endl;

    return 0;
}
