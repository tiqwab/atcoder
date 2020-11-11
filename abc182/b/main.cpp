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

    vector<int> as(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    int mx_n = 0;
    int mx_v = -1;
    for (int i = 2; i <= 1000; i++) {
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (as[j] % i == 0) {
                cnt++;
            }
        }
        if (cnt > mx_n) {
            mx_n = cnt;
            mx_v = i;
        }
    }

    cout << mx_v << endl;

    return 0;
}
