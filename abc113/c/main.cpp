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

vector<vector<pair<int, int>>> cities;
vector<pair<int, int>> ids;

int main(void) {
    int N, M;
    cin >> N >> M;

    cities.resize(N);
    ids.resize(M);

    for (int i = 0; i < M; i++) {
        int p, y;
        cin >> p >> y;
        p--;
        cities[p].push_back({y, i});
    }
    for (int i = 0; i < N; i++) {
        sort(cities[i].begin(), cities[i].end());

        for (int j = 0; j < (int) cities[i].size(); j++) {
            ids[cities[i][j].second] = {i + 1, j + 1};
        }
    }

    for (int i = 0; i < M; i++) {
        printf("%06d%06d\n", ids[i].first, ids[i].second);
    }

    return 0;
}
