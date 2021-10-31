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

vector<string> hands;

// return > 0 if c1 wins
int janken(const char c1, const char c2) {
    if (c1 == 'G') {
        if (c2 == 'G') {
            return 0;
        } else if (c2 == 'C') {
            return 1;
        } else {
            return -1;
        }
    } else if (c1 == 'C') {
        if (c2 == 'G') {
            return -1;
        } else if (c2 == 'C') {
            return 0;
        } else {
            return 1;
        }
    } else {
        if (c2 == 'G') {
            return 1;
        } else if (c2 == 'C') {
            return -1;
        } else {
            return 0;
        }
    }
}

int main(void) {
    int N, M;
    cin >> N >> M;

    hands.resize(2 * N);
    for (int i = 0; i < 2 * N; i++) {
        cin >> hands[i];
    }

    // { wins, id }
    set<pair<int, int>> scores;
    for (int i = 0; i < 2 * N; i++) {
        scores.insert(make_pair(0, i));
    }

    for (int m = 0; m < M; m++) {
        set<pair<int, int>> tmp;

        auto it = scores.begin();
        while (it != scores.end()) {
            const auto p1 = *it;
            it++;
            const auto p2 = *it;
            it++;

            const int result = janken(hands[p1.second][m], hands[p2.second][m]);
            if (result > 0) {
                // p1 win
                tmp.insert(make_pair(p1.first - 1, p1.second));
                tmp.insert(make_pair(p2.first, p2.second));
            } else if (result < 0) {
                // p2 win
                tmp.insert(make_pair(p1.first, p1.second));
                tmp.insert(make_pair(p2.first - 1, p2.second));
            } else {
                // draw
                tmp.insert(make_pair(p1.first, p1.second));
                tmp.insert(make_pair(p2.first, p2.second));
            }
        }

        swap(scores, tmp);
    }

    for (auto p : scores) {
        cout << p.second + 1 << endl;
    }

    return 0;
}
