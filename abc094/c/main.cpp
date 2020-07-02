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

vector<int> xs;
vector<int> ys;

int main(void) {
    int N;
    cin >> N;

    xs.resize(N);
    ys.resize(N);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        xs[i] = x;
        ys[i] = x;
    }

    sort(ys.begin(), ys.end());

    int left = ys[(int) ys.size() / 2 - 1];
    int right = ys[(int) ys.size() / 2];
    // printf("left: %d, right: %d\n", left, right);

    for (int i = 0; i < N; i++) {
        if (xs[i] <= left) {
            printf("%d\n", right);
        } else {
            printf("%d\n", left);
        }
    }

    return 0;
}
