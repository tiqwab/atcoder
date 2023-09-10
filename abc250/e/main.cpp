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
    int N;
    cin >> N;

    const int INF = INT_MAX / 2;

    map<int, int> a_to_n;
    int n = 1;

    set<int> sa;
    vector<int> ca(N + 1, 0); // number in group
    vector<int> ma(N + 1, 0); // max number in group
    vector<int> as;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        as.push_back(a);
        sa.insert(a);
        ca[i + 1] = sa.size();
        if (a_to_n.find(a) == a_to_n.end()) {
            a_to_n[a] = n;
            n++;
        }
        ma[i + 1] = max(ma[i], a_to_n[a]);
    }

    set<int> sb;
    vector<int> cb(N + 1, 0); // number in group
    vector<int> mb(N + 1, 0); // max number in group
    vector<int> bs;
    for (int i = 0; i < N; i++) {
        int b;
        cin >> b;
        bs.push_back(b);
        if (a_to_n.find(b) != a_to_n.end()) {
            sb.insert(b);
            cb[i + 1] = sb.size();
            mb[i + 1] = max(mb[i], a_to_n[b]);
        } else {
            sb.insert(INF);
            cb[i + 1] = sb.size();
            mb[i + 1] = INF;
        }
    }

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int x, y;
        cin >> x >> y;

        // printf("%d, %d, %d, %d\n", ca[x], cb[y], ma[x], mb[y]);

        if (ca[x] == cb[y] && ma[x] == mb[y]) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}
