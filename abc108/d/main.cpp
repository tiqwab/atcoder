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

int n = 0;

// {from, to, weight}
vector<tuple<int, int, int>> edges;

// based on the official YouTube video.
int main(void) {
    int L;
    cin >> L;
    L--;

    edges.push_back(make_tuple(1, 2, 0));
    edges.push_back(make_tuple(1, 2, 1));
    n += 2;

    vector<int> as;
    while (L != 1) {
        if (L % 2 == 0) {
            as.push_back(0);
            L--;
        } else {
            as.push_back(1);
            L /= 2;
        }
    }
    reverse(as.begin(), as.end());

    int acc = 1;
    for (auto a : as) {
        if (a == 0) {
            edges.push_back(make_tuple(1, n, acc + 1));
            acc += 1;
        } else {
            for (int i = 0; i < (int) edges.size(); i++) {
                auto edge = edges[i];
                int u, v, w;
                tie(u, v, w) = edge;
                edges[i] = make_tuple(u, v, w * 2);
            }

            edges.push_back(make_tuple(n, n + 1, 0));
            edges.push_back(make_tuple(n, n + 1, 1));
            n += 1;
            acc = 2 * acc + 1;
        }
    }

    printf("%d %d\n", n, (int) edges.size());
    for (auto &edge : edges) {
        int u, v, w;
        tie(u, v, w) = edge;
        printf("%d %d %d\n", u, v, w);
    }

    return 0;
}
