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
    int N;
    cin >> N;

    int dist_sum = 0;

    as.resize(N + 2);
    as[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> as[i];
        dist_sum += abs(as[i] - as[i - 1]);
    }
    as[N + 1] = 0;
    dist_sum += abs(as[N + 1] - as[N]);

    // printf("dist_sum: %d\n", dist_sum);

    for (int i = 1; i <= N; i++) {
        cout << dist_sum - abs(as[i - 1] - as[i]) - abs(as[i] - as[i + 1]) + abs(as[i - 1] - as[i + 1]) << endl;
    }

    return 0;
}
