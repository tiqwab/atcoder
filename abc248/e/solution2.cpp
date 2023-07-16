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

bool check(const pair<int, int> v1, const pair<int, int> v2, const pair<int, int> cand) {
    const ll val1 = (v2.second - v1.second) * (v2.first - cand.first);
    const ll val2 = (v2.second - cand.second) * (v2.first - v1.first);
    return val1 == val2;
}

int main(void) {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> vertices;
    for (int i = 0 ; i < N; i++) {
        int x, y;
        cin >> x >> y;
        vertices.push_back(make_pair(x, y));
    }

    if (K == 1) {
        printf("Infinity\n");
        return 0;
    }

    int ans = 0;

    set<set<int>> groups;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            set<int> group;
            auto v1 = vertices[i];
            auto v2 = vertices[j];
            group.insert(i);
            group.insert(j);

            int count = 2;

            for (int k = 0; k < N; k++) {
                if (k == i || k == j) {
                    continue;
                }
                if (check(v1, v2, vertices[k])) {
                    count++;
                    group.insert(k);
                }
            }

            if (count >= K) {
                if (groups.find(group) == groups.end()) {
                    ans += 1;
                    groups.insert(group);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
