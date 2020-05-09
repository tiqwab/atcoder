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

vector<int> xs;
vector<int> ys;

int main(void) {
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;

    int xmin = X;
    int xmax = X;
    int ymin = Y;
    int ymax = Y;

    xs.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> xs[i];
        chmin(xmin, xs[i]);
        chmax(xmax, xs[i]);
    }

    ys.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> ys[i];
        chmin(ymin, ys[i]);
        chmax(ymax, ys[i]);
    }

    if (xmax < ymin) {
        cout << "No War" << endl;
    } else {
        cout << "War" << endl;
    }

    return 0;
}
