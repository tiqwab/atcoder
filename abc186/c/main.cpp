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

bool check(const int n) {
    // for 10
    {
        int x = n;
        while (x != 0) {
            if (x % 10 == 7) {
                return false;
            }
            x /= 10;
        }
    }

    // for 8
    {
        int x = n;
        while (x != 0) {
            if (x % 8 == 7) {
                return false;
            }
            x /= 8;
        }
    }

    return true;
}

int main(void) {
    int N;
    cin >> N;

    int cnt = 0;

    for (int i = 1; i <= N; i++) {
        if (check(i)) {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
