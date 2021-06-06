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

map<int, vector<int>> row_to_pones;

int main(void) {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y;
        row_to_pones[X].push_back(Y);
    }

    set<int> poss;
    poss.insert(N);

    for (auto rtp : row_to_pones) {
        // const int row = rtp.first;
        auto pones = rtp.second;
        set<int> removed;
        set<int> inserted;
        for (auto p : pones) {
            if (poss.find(p) != poss.end()) {
                removed.insert(p);
            }
            if (poss.find(p - 1) != poss.end() || poss.find(p + 1) != poss.end()) {
                inserted.insert(p);
            }
        }
        for (auto p : removed) {
            poss.erase(p);
        }
        for (auto p : inserted) {
            poss.insert(p);
        }
    }

#ifdef DEBUG
    printf("poss: \n");
    for (auto p : poss) {
        cout << p << " ";
    }
    cout << endl;
#endif

    cout << poss.size() << endl;

    return 0;
}
