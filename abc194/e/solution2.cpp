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

vector<int> as;
map<int, set<int>> a_to_pos;

int main(void) {
    int N, M;
    cin >> N >> M;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
        a_to_pos[as[i]].insert(i + 1);
    }

    int ans = N;

    for (int i = 0; i < N; i++) {
        set<int> ss = a_to_pos[i];
        ss.insert(0);
        ss.insert(N + 1);

        bool ok = false;

        auto it = ss.begin();
        int prev = *it;
        it++;
        while (it != ss.end()) {
            int cur = *it;
            if (cur - prev > M) {
                ok = true;
                break;
            }
            prev = cur;
            it++;
        }

        if (ok) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
