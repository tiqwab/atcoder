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
    string S;
    cin >> S;

    set<char> should_include;
    set<char> shouldnot_include;

    for (int i = 0; i < 10; i++) {
        if (S[i] == 'o') {
            should_include.insert(i + '0');
        } else if (S[i] == 'x') {
            shouldnot_include.insert(i + '0');
        }
    }

    int ans = 0;

    for (int i = 0; i < 10000; i++) {
        string s;

        int x = i;
        while (x > 0) {
            char c = (x % 10) + '0';
            s.push_back(c);
            x /= 10;
        }
        while ((int) s.size() < 4) {
            s.push_back('0');
        }
        reverse(s.begin(), s.end());

        map<char, int> counter;
        for (int j = 0; j < 4; j++) {
            char c = s[j];
            counter[c]++;
        }

        bool ok = true;
        for (auto c : should_include) {
            if (counter[c] == 0) {
                ok = false;
            }
        }
        for (auto c : shouldnot_include) {
            if (counter[c] > 0) {
                ok = false;
            }
        }
        if (ok) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
