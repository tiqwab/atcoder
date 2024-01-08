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

    multiset<int> s;

    for (int i = 0; i < Q; i++) {
        int q;
        cin >> q;
        if (q == 1) {
            int x;
            cin >> x;
            s.insert(x);
        } else if (q == 2) {
            int x, c;
            cin >> x >> c;
            auto it = s.find(x);
            while (it != s.end() && c > 0 && *it == x) {
                it = s.erase(it);
                c--;
            }
        } else {
            int min_value = *s.begin();
            int max_value = *s.rbegin();
            printf("%d\n", max_value - min_value);
        }
    }

    return 0;
}
