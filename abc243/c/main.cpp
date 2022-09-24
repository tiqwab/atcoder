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

    vector<int> xs(N);
    vector<int> ys(N);

    for (int i = 0; i < N; i++) {
        cin >> xs[i];
        cin >> ys[i];
    }

    string S;
    cin >> S;

    // y -> (x, dir)
    map<int, vector<pair<int, char>>> y_to_xs;

    for (int i = 0; i < N; i++) {
        y_to_xs[ys[i]].push_back(make_pair(xs[i], S[i]));
    }


    bool ok = false;

    for (auto &ps : y_to_xs) {
        sort(ps.second.begin(), ps.second.end());

        bool left_found = false;
        bool right_found = false;
        for (auto &p : ps.second) {
            const char dir = p.second;

            if (!left_found) {
                if (dir == 'R') {
                    left_found = true;
                }
            } else {
                if (dir == 'L') {
                    right_found = true;
                    break;
                }
            }
        }
        if (left_found && right_found) {
            ok = true;
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
