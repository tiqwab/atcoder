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
    int Q;
    cin >> Q;

    queue<int> que;
    multiset<int> se;

    for (int i = 0; i < Q; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int x;
            cin >> x;
            que.push(x);
        } else if (a == 2) {
            if (se.size() > 0) {
                auto it = se.begin();
                printf("%d\n", *it);
                se.erase(it);
            } else {
                printf("%d\n", que.front());
                que.pop();
            }
        } else {
            while (!que.empty()) {
                int x = que.front();
                que.pop();
                se.insert(x);
            }
        }
    }

    return 0;
}
