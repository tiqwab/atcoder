#include <algorithm>
#include <cassert>
#include <iostream>
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

void generate(vector<int> vec, vector<vector<int>> &acc, const vector<int> P, const int selected, const int N) {
    if (selected == ((1 << N) - 1)) {
        acc.push_back(vec);
        return;
    }

    for (int i = 0; i < N; i++) {
        if ((selected | (1 << i)) != selected) {
            vec.push_back(P[i]);
            generate(vec, acc, P, selected | (1 << i), N);
            vec.pop_back();
        }
    }
}

int find(const vector<int> &xs, const vector<vector<int>> &acc) {
    for (int i = 0; i < (int) acc.size(); i++) {
        if (xs == acc[i]) {
            return i;
        }
    }

    return -1;
}

int main(void) {
    int N;
    cin >> N;

    vector<int> P(N), Q(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> Q[i];
    }

    vector<int> t;
    for (int i = 0; i < N; i++) {
        t.push_back(i+1);
    }

    vector<vector<int>> acc;
    vector<int> s;
    generate(s, acc, t, 0, N);

    // for (int i = 0; i < (int) acc.size(); i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << acc[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int pi = find(P, acc);
    int qi = find(Q, acc);
    assert(pi >= 0 && qi >= 0);

    cout << abs(pi - qi) << endl;

    return 0;
}
