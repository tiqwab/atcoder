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

int main(void) {
    int N;
    cin >> N;
    vector<int> ps(N);
    int sum = 0;
    int maximum = 0;
    for (int i = 0; i < N; i++) {
        cin >> ps[i];
        sum += ps[i];
        chmax(maximum, ps[i]);
    }

    sum -= maximum / 2;
    cout << sum << endl;

    return 0;
}
