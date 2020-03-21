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
    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;

    vector<int> dishes(5);
    dishes[0] = A;
    dishes[1] = B;
    dishes[2] = C;
    dishes[3] = D;
    dishes[4] = E;

    vector<int> ceils(5);
    for (int i = 0; i < 5; i++) {
        ceils[i] = ((dishes[i] + 10 - 1) / 10) * 10;
    }

    vector<int> rems(5);
    for (int i = 0; i < 5; i++) {
        rems[i] = ceils[i] - dishes[i];
    }

    int ans = 0;
    for (int i = 0; i < 5; i++) {
        ans += ceils[i];
    }
    ans -= *max_element(rems.begin(), rems.end());

    cout << ans << endl;

    return 0;
}
