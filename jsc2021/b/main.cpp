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

const int MAX_A = 1000;

int main(void) {
    int N, M;
    cin >> N >> M;

    vector<int> counter(MAX_A + 1, 0);

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        counter[a]++;
    }

    for (int i = 0; i < M; i++) {
        int b;
        cin >> b;
        counter[b]++;
    }

    vector<int> ans;
    for (int i = 1; i < MAX_A + 1; i++) {
        if (counter[i] == 1) {
            ans.push_back(i);
        }
    }

    for (int i = 0; i < (int) ans.size(); i++) {
        if (i == 0) {
            printf("%d", ans[i]);
        } else {
            printf(" %d", ans[i]);
        }
    }
    printf("\n");

    return 0;
}
