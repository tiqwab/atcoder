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

const ll INF = LONG_LONG_MAX / 2;

vector<vector<ll>> orig_board;

ll solve(vector<vector<ll>> board, const int H, const int W, const int C) {
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            board[h][w] += C * ll(h + w);
        }
    }
#ifdef DEBUG
    printf("board: \n");
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            cout << board[h][w] << " ";
        }
        cout << endl;
    }
#endif

    vector<vector<ll>> acc(H + 1, vector<ll>(W + 1, INF));
    for (int h = H - 1; h >= 0; h--) {
        for (int w = W - 1; w >= 0; w--) {
            ll cand = INF;
            chmin(cand, acc[h + 1][w]);
            chmin(cand, acc[h][w + 1]);
            if (h < H - 1) {
                chmin(cand, board[h + 1][w]);
            }
            if (w < W - 1) {
                chmin(cand, board[h][w + 1]);
            }
            acc[h][w] = cand;
        }
    }
#ifdef DEBUG
    printf("acc: \n");
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            cout << acc[h][w] << " ";
        }
        cout << endl;
    }
#endif

    ll ans = INF;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            ll cand = board[h][w] + acc[h][w] - 2 * C * ll(h + w);
#ifdef DEBUG
            printf("h: %d, w: %d, = %lld\n", h, w, cand); 
#endif
            chmin(ans, cand);
        }
    }
    return ans;
}

int main(void) {
    int H, W;
    ll C;
    cin >> H >> W >> C;

    orig_board.resize(H, vector<ll>(W, 0));
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            cin >> orig_board[h][w];
        }
    }

    ll ans = INF;
    chmin(ans, solve(orig_board, H, W, C));
    reverse(orig_board.begin(), orig_board.end());
    chmin(ans, solve(orig_board, H, W, C));
    cout << ans << endl;

    return 0;
}
