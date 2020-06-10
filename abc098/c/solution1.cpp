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

const int INF = INT_MAX / 2;

vector<int> wes;
vector<int> eas;

int main(void) {
    int N;
    cin >> N;
    string S;
    cin >> S;
    const int slen = (int) S.size();

    for (int i = 0; i < slen; i++) {
        if (S[i] == 'E') {
            eas.push_back(i);
        } else {
            wes.push_back(i);
        }
    }

    int ans = INF;
    for (int i = 0; i < N; i++) {
        int cnt = 0;

        auto it_right = upper_bound(eas.begin(), eas.end(), i);
        cnt += distance(it_right, eas.end());
        auto it_left = lower_bound(wes.begin(), wes.end(), i);
        cnt += distance(wes.begin(), it_left);
        // printf("i: %d, right: %ld, left: %ld\n", i, distance(it_right, eas.end()), distance(wes.begin(), it_left));

        chmin(ans, cnt);
    }

    cout << ans << endl;

    return 0;
}
