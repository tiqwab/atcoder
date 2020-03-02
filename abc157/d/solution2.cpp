#include <algorithm>
#include <iostream>
#include <vector>

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

/*
 * ref. [Union-Find](https://www.slideshare.net/chokudai/union-find-49066733)
 * ref. [AtCoder ABC 157 - AtCoder Live](https://www.youtube.com/watch?v=TdR816rqc3s)
 */
class UnionFind {
    public:
        UnionFind(int n = 0): d(n, -1) {}

        // 0-index, [0, n) in other words
        int find(int x) {
            if (d[x] < 0) return x;
            return d[x] = find(d[x]);
        }

        // Return false if x and y are alreday in the same group, otherwise return true.
        // 0-index, [0, n) in other words
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
        bool same(int x, int y) {
            return find(x) == find(y);
        }

        // 0-index, [0, n) in other words
        int size(int x) {
            return -d[find(x)];
        }

    private:
        vector<int> d;
};

vector<vector<int>> friends;
vector<vector<int>> blocks;

// Solution with Union-Find
int main(void) {
    int N, M, K;
    cin >> N >> M >> K;

    UnionFind uf(N);

    friends.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        uf.unite(a, b);
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    blocks.resize(N);
    for (int i = 0; i < K; i++) {
        int c, d;
        cin >> c >> d;
        c--;
        d--;
        blocks[c].push_back(d);
        blocks[d].push_back(c);
    }

    for (int i = 0; i < N; i++) {
        int ans = uf.size(i);
        ans--; // remove myself
        ans -= friends[i].size(); // remove friends
        for (auto v : blocks[i]) {
            if (uf.same(i, v)) {
                ans--;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
