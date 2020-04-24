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

vector<int> as;

int main(void) {
    int N, M;
    cin >> N >> M;

    int sum = 0;
    as.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> as[i];
        sum += as[i];
    }

    if (sum > N) {
        cout << "-1" << endl;
    } else {
        cout << N - sum << endl;
    }

    return 0;
}
