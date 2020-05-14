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

typedef pair<int, int> point;

int H, W;
vector<int> coins;
vector<point> cells;

vector<pair<point, point>> ans;

int main(void) {
    cin >> H >> W;


    for (int h = 0; h < H; h++) {
        vector<int> tmp_coins(W);
        vector<point> tmp_cells(W);
        for (int w = 0; w < W; w++) {
            cin >> tmp_coins[w];
            tmp_cells[w] = {h, w};
        }
        if (h % 2 != 0) {
            reverse(tmp_coins.begin(), tmp_coins.end());
            reverse(tmp_cells.begin(), tmp_cells.end());
        }
        for (int w = 0; w < W; w++) {
            coins.push_back(tmp_coins[w]);
            cells.push_back(tmp_cells[w]);
        }
    }

    // for (int i = 0; i < H * W; i++) {
    //     printf("(%d, %d): %d\n", cells[i].first, cells[i].second, coins[i]);
    // }

    for (int i = 0; i < H * W - 1; i++) {
        if (coins[i] % 2 != 0) {
            ans.push_back({cells[i], cells[i + 1]});
            coins[i]--;
            coins[i + 1]++;
        }
    }

    printf("%d\n", (int) ans.size());
    for (auto &path : ans) {
        auto from = path.first;
        auto to = path.second;
        printf("%d %d %d %d\n", from.first + 1, from.second + 1, to.first + 1, to.second + 1);
    }

    return 0;
}
