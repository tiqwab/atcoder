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

    vector<vector<int>> boxes(M, vector<int>());
    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            boxes[i].push_back(a);
        }
    }

    // {number, box_no}
    map<int, vector<int>> m;

    for (int i = 0; i < M; i++) {
        reverse(boxes[i].begin(), boxes[i].end());
        int a = boxes[i].back();
        boxes[i].pop_back();
        m[a].push_back(i);
    }

    set<int> oks;
    for (auto p : m) {
        if (p.second.size() == 2) {
            oks.insert(p.first);
        }
    }

    vector<bool> done(N, false);

    while (!oks.empty()) {
        auto it = oks.begin();
        const int cur_number = *it;

#ifdef DEBUG
        printf("process %d\n", cur_number);
#endif

        assert(m[cur_number].size() == 2);
        for (auto idx : m[cur_number]) {
            if (boxes[idx].size() > 0) {
                int a = boxes[idx].back();
                boxes[idx].pop_back();
                m[a].push_back(idx);
                if (m[a].size() == 2) {
                    oks.insert(a);
                }
            }
        }

        done[cur_number - 1] = true;
        oks.erase(it);
    }

    bool ok = true;
    for (int i = 0; i < N; i++) {
        if (!done[i]) {
            ok = false;
            break;
        }
    }

    if (ok) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }


    return 0;
}
