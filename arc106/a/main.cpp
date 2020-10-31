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
    ll N;
    cin >> N;

    ll x = 1;
    for (int i = 1; i < 100; i++) {
        x *= 3;

        if (x >= N) {
            break;
        }

        ll y = 1;
        for (int j = 1; j < 100; j++) {
            y *= 5;

            if (y >= N) {
                break;
            }

            // printf("%d %d %lld %lld\n", i, j, x, y);

            if (x + y > N) {
                break;
            }

            if (x + y == N) {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
