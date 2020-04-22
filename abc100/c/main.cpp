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

int twos(int a) {
    int cnt = 0;
    while (a % 2 == 0) {
        cnt++;
        a /= 2;
    }
    return cnt;
}

int main(void) {
    int N;
    cin >> N;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        cnt += twos(as[i]);
    }

    cout << cnt << endl;

    return 0;
}
