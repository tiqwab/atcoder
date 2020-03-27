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
    string S;
    cin >> S;
    int slen = (int) S.size();

    set<char> cs;
    cs.insert('A');
    cs.insert('C');
    cs.insert('G');
    cs.insert('T');

    int ans = 0;
    for (int i = 0; i <= slen; i++) {
        for (int j = i + 1; j <= slen; j++) {
            // [i, j)
            bool ok = true;
            for (int k = i; k < j; k++) {
                if (cs.find(S[k]) == cs.end()) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                chmax(ans, j - i);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
