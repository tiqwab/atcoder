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

map<int, int> doubles;

int solve(const int N) {
    int ans = 0;

    for (int x = 1; x < 100; x++) {
        for (int y = 1; y < 100; y++) {
            const int v = (x + y) * (x + y) - 4 * (x * x + y * y + x * y - N);
            if (v < 0) {
                continue;
            }
            if (doubles.find(v) == doubles.end()) {
                continue;
            }

            const int z2 =  -1 * (x + y) + doubles[v];
            if (z2 <= 0) {
                continue;
            }
            if (z2 % 2 == 0) {
                // printf("x: %d, y: %d, z: %d\n", x, y, z2 / 2);
                ans++;
            }
        }
    }

    return ans;
}

int main(void) {
    int N;
    cin >> N;

    // prepare doubles
    for (int i = 0; i <= 1000; i++) {
        doubles[i * i] = i;
    }

    for (int i = 1; i <= N; i++) {
        // printf("%d: \n", i);
        printf("%d\n", solve(i));
    }

    return 0;
}
