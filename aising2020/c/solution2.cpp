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
    int N;
    cin >> N;

    vector<int> ans(N + 1);

    for (int x = 1; x * x < N; x++) {
        for (int y = 1; y * y < N; y++) {
            for (int z = 1; z * z < N; z++) {
                ll v = x * x + y * y + z * z + x * y + y * z + z * x;
                if (v > N) {
                    continue;
                }
                ans[v]++;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}
