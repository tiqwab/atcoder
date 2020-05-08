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

// {x, y}
vector<pair<int, int>> points;
vector<int> dist;
int max_dist;

int main(void) {
    int N;
    cin >> N;

    points.resize(N);
    dist.resize(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
        dist[i] = abs(x) + abs(y);
        chmax(max_dist, dist[i]);
    }

    {
        bool ok = true;
        for (int i = 1; i < N; i++) {
            if (dist[i - 1] % 2 != dist[i] % 2) {
                ok = false;
            }
        }
        if (!ok) {
            cout << "-1" << endl;
            return 0;
        }
    }

    if (max_dist > 20) {
        printf("not yet implemented for max_dist: %d\n", max_dist);
        return 0;
    }

    // answer for 300
    {
        cout << max_dist << endl;

        cout << "1";
        for (int i = 1; i < max_dist; i++) {
            cout << " " << 1;
        }
        cout << endl;

        for (int i = 0; i < N; i++) {
            int px = points[i].first;
            int py = points[i].second;
            int px_dist = abs(points[i].first);
            int py_dist = abs(points[i].second);
            int dist = 0;

            for (int x = 0; x < px_dist; x++) {
                if (px > 0) {
                    cout << "R";
                } else {
                    cout << "L";
                }
                dist++;
            }

            for (int y = 0; y < py_dist; y++) {
                if (py > 0) {
                    cout << "U";
                } else {
                    cout << "D";
                }
                dist++;
            }

            // consume remain arms.
            // max_dist - dist is always even (including 0).
            while (dist < max_dist) {
                if (dist % 2 == 0) {
                    cout << "R";
                } else {
                    cout << "L";
                }
                dist++;
            }

            cout << endl;
        }
    }

    return 0;
}
