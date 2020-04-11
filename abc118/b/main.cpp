#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
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

vector<int> ms;

int main(void) {
    int N, M;
    cin >> N >> M;

    ms.resize(M);

    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;
        for (int j = 0; j < K; j++) {
            int a;
            cin >> a;
            a--;
            ms[a]++;
        }
    }

    int cnt = 0;
    for (int i = 0; i < (int) ms.size(); i++) {
        if (ms[i] == N) {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
