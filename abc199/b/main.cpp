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

const int MAX_A = 1000;

int main(void) {
    int N;
    cin >> N;

    vector<int> as(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
        as[i]--;
    }

    vector<int> bs(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> bs[i];
        bs[i]--;
    }

    vector<int> counter(MAX_A, 0);

    for (int i = 0; i < N; i++) {
        const int a = as[i];
        const int b = bs[i];
        for (int j = a; j <= b; j++) {
            counter[j]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < MAX_A; i++) {
        if (counter[i] == N) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
