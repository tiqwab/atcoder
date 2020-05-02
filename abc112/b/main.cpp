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
    int N, T;
    cin >> N >> T;

    vector<int> paths;
    for (int i = 0; i < N; i++) {
        int c, t;
        cin >> c >> t;
        if (t <= T) {
            paths.push_back(c);
        }
    }
    sort(paths.begin(), paths.end());

    if (paths.empty()) {
        cout << "TLE" << endl;
    } else {
        cout << paths[0] << endl;
    }

    return 0;
}
