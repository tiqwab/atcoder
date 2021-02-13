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
    int N, X;
    cin >> N >> X;

    bool is_first = true;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (a != X) {
            if (is_first) {
                printf("%d", a);
                is_first = false;
            } else {
                printf(" %d", a);
            }
        }
    }
    printf("\n");

    return 0;
}
