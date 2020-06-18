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

const int MAX_A = 1000 * 1000;

vector<int> as;
int ns[MAX_A + 1];

// solution based on the video
int main(void) {
    int N;
    cin >> N;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }
    sort(as.begin(), as.end());

    for (int i = 0; i < N; i++) {
        int x = as[i];
        ns[x]++;
        if (ns[x] >= 2) {
            continue;
        }
        for (int j = x + x; j <= MAX_A; j += x) {
            ns[j]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (ns[as[i]] == 1) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
