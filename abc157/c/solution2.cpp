#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

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

int solve(const vector<pair<int, int>> sc, const int N, const int M) {
    vector<set<int>> ords(N);
    for (int i = 0; i < M; i++) {
        ords[sc[i].first].insert(sc[i].second);
    }

    // -1 if contradicted
    for (int i = 0; i < N; i++) {
        if ((int) ords[i].size() > 1) {
            return -1;
        }
    }

    // such as 0 x x
    if (((int) ords[0].size()) == 1 && *ords[0].begin() == 0) {
        if (N == 1) {
            return 0;
        } else {
            return -1;
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (((int) ords[i].size()) == 1) {
            ans = ans * 10 + *ords[i].begin();
        } else {
            if (i == 0 && ords[i].size() == 0 && N != 1) {
                ans = 1;
            } else {
                ans = ans * 10;
            }
        }
    }
    return ans;
}

int main(void) {
    int N, M;
    cin >> N >> M;
    
    vector<pair<int, int>> sc(M);
    for (int i = 0; i < M; i++) {
        int s, c;
        cin >> s >> c;
        s--;
        sc[i] = {s, c};
    }

    cout << solve(sc, N, M) << endl;
    
    return 0;
}
