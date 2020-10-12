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

const ll MOD = 1000000007;

// auto mod int
// ref. https://github.com/atcoder-live/library/blob/master/mint.cpp
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%MOD+MOD)%MOD){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += MOD-a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= MOD;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime MOD
  mint inv() const {
    return pow(MOD-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};

/*
 * ref. [Union-Find](https://www.slideshare.net/chokudai/union-find-49066733)
 * ref. [AtCoder ABC 157 - AtCoder Live](https://www.youtube.com/watch?v=TdR816rqc3s)
 */
class UnionFind {
    public:
        UnionFind(int n = 0): d(n, -1) {}

        // 0-index, [0, n) in other words
        // Time complexity: O(a(n)) (a = inverse Achkermann function)
        int find(int x) {
            if (d[x] < 0) return x;
            return d[x] = find(d[x]);
        }

        // Return false if x and y are alreday in the same group, otherwise return true.
        // 0-index, [0, n) in other words
        // Time complexity: O(a(n)) (a = inverse Achkermann function)
        bool unite(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) return false;
            if (d[x] > d[y]) swap(x, y);
            d[x] += d[y];
            d[y] = x;
            return true;
        }

        // 0-index, [0, n) in other words
        // Time complexity: O(a(n)) (a = inverse Achkermann function)
        bool same(int x, int y) {
            return find(x) == find(y);
        }

        // 0-index, [0, n) in other words
        // Time complexity: O(1)
        int size(int x) {
            return -d[find(x)];
        }

    private:
        vector<int> d;
};

vector<vector<char>> board;
vector<int> empty_floor_for_h;
vector<int> empty_floor_for_w;
int num_empty_floor = 0;

vector<ll> twos;

int main(void) {
    int H, W;
    cin >> H >> W;

    board.resize(H + 1, vector<char>(W + 1, '#'));
    empty_floor_for_h.resize(H);
    empty_floor_for_w.resize(W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c;
            cin >> c;
            board[i][j] = c;
            if (c == '.') {
                num_empty_floor++;
                empty_floor_for_h[i]++;
                empty_floor_for_w[j]++;
            }
        }
    }
#ifdef DEBUG
    printf("empty_floor_for_h: \n");
    for (int h = 0; h < H; h++) {
        printf("%d\n", empty_floor_for_h[h]);
    }
    printf("\n");
    printf("empty_floor_for_w: \n");
    for (int w = 0; w < W; w++) {
        printf("%d ", empty_floor_for_w[w]);
    }
    printf("\n");
    printf("\n");
#endif

    twos.resize(H * W + 1);
    twos[0] = 1;
    for (int i = 1; i <= H * W; i++) {
        twos[i] = (twos[i - 1] * 2) % MOD;
    }

    // group_per_h[h][w] is the gorup size of board[h][w] (only count w axis)
    vector<vector<int>> group_per_h(H, vector<int>(W, 0));

    for (int h = 0; h < H; h++) {
        UnionFind uf(W + 1);
        for (int w = 0; w < W; w++) {
            if (board[h][w] == '.' && board[h][w + 1] == '.') {
                uf.unite(w, w + 1);
            }
        }
        for (int w = 0; w < W; w++) {
            if (board[h][w] == '.') {
                group_per_h[h][w] = uf.size(w);
            }
        }
    }
#ifdef DEBUG
    printf("group_per_h: \n");
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            printf("%d ", group_per_h[h][w]);
        }
        printf("\n");
    }
    printf("\n");
#endif

    // group_per_h[w][h] is the gorup size of board[h][w] (only count h axis)
    vector<vector<int>> group_per_w(W, vector<int>(H, 0));
    for (int w = 0; w < W; w++) {
        UnionFind uf(H + 1);
        for (int h = 0; h < H; h++) {
            if (board[h][w] == '.' && board[h + 1][w] == '.') {
                uf.unite(h, h + 1);
            }
        }
        for (int h = 0; h < H; h++) {
            if (board[h][w] == '.') {
                group_per_w[w][h] = uf.size(h);
            }
        }
    }
#ifdef DEBUG
    printf("group_per_w: \n");
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            printf("%d ", group_per_w[w][h]);
        }
        printf("\n");
    }
    printf("\n");
#endif

    auto f = [](const int x) {
        return twos[x];
    };

    mint ans = 0;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            mint x = f(group_per_h[h][w]) - 1;
            x *= f(num_empty_floor - group_per_h[h][w]);

            mint y = f(group_per_w[w][h]) - 1;
            y *= f(num_empty_floor - group_per_w[w][h]);

            mint z = 0;
            if (group_per_h[h][w] > 0 && group_per_w[w][h] > 0) {
                z = f(group_per_h[h][w] - 1) * f(group_per_w[w][h] - 1);
                z += (f(group_per_h[h][w] - 1) - 1) * (f(group_per_w[w][h] - 1) - 1);
                z *= f(num_empty_floor - group_per_h[h][w] - group_per_w[w][h] + 1);
            }

#ifdef DEBUG
            printf("x: %lld, y: %lld, z: %lld\n", x.x, y.x, z.x);
#endif
            ans += x + y - z;
        }
    }

    cout << ans.x << endl;
    return 0;
}
