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

int main(void) {
    int H, W, N;
    cin >> H >> W >> N;

    // {h, idx}
    vector<pair<int, int>> hs;
    // {w, idx}
    vector<pair<int, int>> ws;

    for (int i = 0; i < N; i++) {
        int h, w;
        cin >> h >> w;
        hs.push_back(make_pair(h, i));
        ws.push_back(make_pair(w, i));
    }

    sort(hs.begin(), hs.end());
    sort(ws.begin(), ws.end());

    vector<int> ans_h(N);
    {
        int cur_h = 1;
        ans_h[hs[0].second] = cur_h;
        for (int i = 1; i < N; i++) {
            if (hs[i - 1].first != hs[i].first) {
                cur_h++;
            }
            ans_h[hs[i].second] = cur_h;
        }
    }

#ifdef DEBUG
    printf("ans_h: \n");
    for (int i = 0; i < N; i++) {
        cout << ans_h[i] << " ";
    }
    cout << endl;
    cout << endl;
#endif

    vector<int> ans_w(N);
    {
        int cur_w = 1;
        ans_w[ws[0].second] = cur_w;
        for (int i = 1; i < N; i++) {
            if (ws[i - 1].first != ws[i].first) {
                cur_w++;
            }
            ans_w[ws[i].second] = cur_w;
        }
    }

#ifdef DEBUG
    printf("ans_w: \n");
    for (int i = 0; i < N; i++) {
        cout << ans_w[i] << " ";
    }
    cout << endl;
    cout << endl;
#endif

    for (int i = 0; i < N; i++) {
        printf("%d %d\n", ans_h[i], ans_w[i]);
    }

    return 0;
}
