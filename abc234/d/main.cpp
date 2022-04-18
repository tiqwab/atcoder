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
    int N, K;
    cin >> N >> K;

    vector<int> ps;
    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        ps.push_back(p);
    }

    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < K; i++) {
        q.push(ps[i]);
    }
    printf("%d\n", q.top());

    for (int i = K; i < N; i++) {
        auto x = q.top();
        if (x < ps[i]) {
            q.pop();
            q.push(ps[i]);
        }
        x = q.top();
        printf("%d\n", x);
    }

    return 0;
}
