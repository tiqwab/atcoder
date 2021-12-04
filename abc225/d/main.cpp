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

vector<int> ft;
vector<int> bt;

void print_for(const int target) {
    // calc the top train
    int top = target;
    while (bt[top] != -1) {
        top = bt[top];
    }

    vector<int> acc;

    int cur = top;
    while (cur != -1) {
        acc.push_back(cur);
        cur = ft[cur];
    }

    printf("%d", (int) acc.size());
    for (auto x : acc) {
        printf(" %d", x + 1);
    }
    printf("\n");
}

int main(void) {
    int N, Q;
    cin >> N >> Q;

    ft.resize(N, -1);
    bt.resize(N, -1);

    for (int i = 0; i < Q; i++) {
        int a, x, y;
        cin >> a;
        if (a == 1) {
            cin >> x >> y;
            x--;
            y--;
            ft[x] = y;
            bt[y] = x;
        } else if (a == 2) {
            cin >> x >> y;
            x--;
            y--;
            ft[x] = -1;
            bt[y] = -1;
        } else {
            cin >> x;
            x--;

            print_for(x);
        }
    }

    return 0;
}
