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

void print(vector<int> &acc) {
    printf("%d", acc[0]);
    for (int i = 1; i < (int) acc.size(); i++) {
        printf(" %d", acc[i]);
    }
    printf("\n");
}

void rec(int cur, vector<int> &acc, const int n, const int m) {
    if ((int) acc.size() == n) {
        print(acc);
    } else {
        for (int i = cur + 1; i <= m; i++) {
            acc.push_back(i);
            rec(i, acc, n, m);
            acc.pop_back();
        }
    }
}

int main(void) {
    int N, M;
    cin >> N >> M;

    vector<int> acc;
    rec(0, acc, N, M);

    return 0;
}
