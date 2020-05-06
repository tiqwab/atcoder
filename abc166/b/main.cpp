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

vector<int> snacks;

int main(void) {
    int N, K;
    cin >> N >> K;

    snacks.resize(N);
    for (int i = 0; i < K; i++) {
        int d;
        cin >> d;
        for (int j = 0; j < d; j++) {
            int a;
            cin >> a;
            a--;
            snacks[a]++;
        }
    }

    int cnt = 0;
    for (int i = 0; i < (int) snacks.size(); i++) {
        if (snacks[i] == 0) {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
