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
    string S;
    cin >> S;

    int ans = 0;
    for (int center = 0; center < N; center++) {
        set<char> found1;
        set<char> found2;
        for (int pos = 0; pos < center; pos++) {
            found1.insert(S[pos]);
        }
        for (int pos = center; pos < N; pos++) {
            found2.insert(S[pos]);
        }

        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            char c = 'a' + i;
            if (found1.find(c) != found1.end() && found2.find(c) != found2.end()) {
                cnt++;
            }
        }
        chmax(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}
