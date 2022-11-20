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
    int N, M;
    cin >> N >> M;

    vector<int> as(N + 1, 0);
    for (int i = 0; i < N + 1; i++) {
        cin >> as[i];
    }
    
    vector<int> bs(M + 1, 0);

    vector<int> cs(N + M + 1);
    for (int i = 0; i < N + M + 1; i++) {
        cin >> cs[i];
    }

    for (int i = 0; i <= M; i++) {
        int c = cs[N + M - i];
        int idx_b = M;
        int idx_a = N - i;
        for (int j = 0; j < i; j++) {
            if (idx_a >= 0) {
                c -= bs[idx_b] * as[idx_a];
            }
            idx_b -= 1;
            idx_a += 1;
        }
        bs[M - i] = c / as[idx_a];
    }

    printf("%d", bs[0]);
    for (int i = 1; i < M + 1; i++) {
        printf(" %d", bs[i]);
    }
    printf("\n");

    return 0;
}
