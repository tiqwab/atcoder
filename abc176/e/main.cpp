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

// {y, x}
set<pair<int, int>> obs;
vector<int> acc_h;
vector<int> acc_w;

// {cnt, h}
vector<pair<int, int>> acc_cnt_h;
// {cnt, w}
vector<pair<int, int>> acc_cnt_w;

int main(void) {
    int H, W, M;
    cin >> H >> W >> M;

    acc_h.resize(H);
    acc_w.resize(W);
    for (int i = 0; i < M; i++) {
        int h, w;
        cin >> h >> w;
        h--;
        w--;
        obs.insert(make_pair(h, w));
        acc_h[h]++;
        acc_w[w]++;
    }

    for (int i = 0; i < H; i++) {
        acc_cnt_h.push_back(make_pair(acc_h[i], i));
    }
    sort(acc_cnt_h.begin(), acc_cnt_h.end());
    reverse(acc_cnt_h.begin(), acc_cnt_h.end());

    for (int i = 0; i < W; i++) {
        acc_cnt_w.push_back(make_pair(acc_w[i], i));
    }
    sort(acc_cnt_w.begin(), acc_cnt_w.end());
    reverse(acc_cnt_w.begin(), acc_cnt_w.end());

#ifdef DEBUG
    printf("acc_cnt_h: \n");
    for (int i = 0; i < H; i++) {
        cout << acc_cnt_h[i].first << " " << acc_cnt_h[i].second << endl;
    }
    printf("acc_cnt_w: \n");
    for (int i = 0; i < W; i++) {
        cout << acc_cnt_w[i].first << " " << acc_cnt_w[i].second << endl;
    }
#endif

    int max_cnt_h = acc_cnt_h[0].first;
    int max_cnt_w = acc_cnt_w[0].first;

    vector<int> max_hs;
    vector<int> max_ws;
    for (auto p : acc_cnt_h) {
        if (p.first != max_cnt_h) {
            break;
        }
        max_hs.push_back(p.second);
    }
    for (auto p : acc_cnt_w) {
        if (p.first != max_cnt_w) {
            break;
        }
        max_ws.push_back(p.second);
    }

    int ans = max_cnt_h + max_cnt_w - 1;
    for (auto h : max_hs) {
        for (auto w : max_ws) {
#ifdef DEBUG
            printf("calc for: h=%d, w=%d\n", h, w);
#endif
            if (obs.find(make_pair(h, w)) == obs.end()) {
                ans = max_cnt_h + max_cnt_w;
                goto end;
            }
        }
    }

end:
    cout << ans << endl;

    return 0;
}
