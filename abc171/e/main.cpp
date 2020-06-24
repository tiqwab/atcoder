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
vector<int> ans;

int main(void) {
    int N;
    cin >> N;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    int xor_all = 0;
    for (int i = 0; i < N; i++) {
        xor_all ^= as[i];
    }

    ans.resize(N);
    for (int i = 0; i < N; i++) {
        ans[i] = xor_all ^ as[i];
    }

    cout << ans[0];
    for (int i = 1; i < N; i++) {
        cout << " " << ans[i];
    }
    cout << endl;

    return 0;
}
