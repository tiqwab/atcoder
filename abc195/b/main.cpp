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

int main(void) {
    int A, B, W;
    cin >> A >> B >> W;

    W *= 1000;

    int min = INF;
    int max = 0;

    for (int n = 1; n <= W; n++) {
        const int w1 = W / n;
        const int w2 = (W % n != 0) ? w1 + 1 : w1;

        if (A <= w1 && w1 <= B && A <= w2 && w2 <= B) {
            chmin(min, n);
            chmax(max, n);
        }
    }

    if (min == INF || max == 0) {
        cout << "UNSATISFIABLE" << endl;
    } else {
        printf("%d %d\n", min, max);
    }

    return 0;
}
