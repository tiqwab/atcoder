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

vector<int> as, bs;

int main(void) {
    int N, K;
    cin >> N >> K;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    bs.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> bs[i];
    }

    int ok_a = true;
    int ok_b = true;
    int a = as[0];
    int b = bs[0];

    for (int i = 1; i < N; i++) {
        int next_ok_a = false;
        int next_ok_b = false;
        int next_a = as[i];
        int next_b = bs[i];

        if (ok_a) {
            if (abs(a - next_a) <= K) {
                next_ok_a = true;
            }
            if (abs(a - next_b) <= K) {
                next_ok_b = true;
            }
        }
        if (ok_b) {
            if (abs(b - next_a) <= K) {
                next_ok_a = true;
            }
            if (abs(b - next_b) <= K) {
                next_ok_b = true;
            }
        }
        ok_a = next_ok_a;
        ok_b = next_ok_b;
        a = next_a;
        b = next_b;
    }

    if (ok_a || ok_b) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
