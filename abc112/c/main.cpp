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

// {x, y, h}
vector<tuple<int, int, int>> points;

bool check(const int cand_x, const int cand_y, const int cand_h, const int N) {
    for (int i = 0; i < N; i++) {
        int x, y, h;
        tie(x, y, h) = points[i];
        if (max(cand_h - abs(x - cand_x) - abs(y - cand_y), 0) != h) {
            return false;
        }
    }
    return true;
}


// {x, y, h}
tuple<int, int, int> solve(const int N) {
    for (int cand_y = 0; cand_y <= 100; cand_y++) {
        for (int cand_x = 0; cand_x <= 100; cand_x++) {
            vector<int> hs;
            for (int i = 0; i < N; i++) {
                int x, y, h;
                tie(x, y, h) = points[i];
                if (h == 0) continue;
                hs.push_back(h + abs(x - cand_x) + abs(y - cand_y));
            }

            bool ok = true;
            for (int i = 1; i < (int) hs.size(); i++) {
                if (hs[i] != hs[i - 1]) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                int cand_h = hs[0];
                if (check(cand_x, cand_y, cand_h, N)) {
                    return tie(cand_x, cand_y, hs[0]);
                }
            }
        }
    }

    int _x = -1, _y = -1, _z = -1;
    return tie(_x, _y, _z);
}

int main(void) {
    int N;
    cin >> N;

    points.resize(N);
    for (int i = 0; i < N; i++) {
        int x, y, h;
        cin >> x >> y >> h;
        points[i] = tie(x, y, h);
    }

    tuple<int, int, int> center = solve(N);
    {
        int x, y, h;
        tie(x, y, h) = center;
        cout << x << " " << y << " " << h << endl;
    }

    return 0;
}
