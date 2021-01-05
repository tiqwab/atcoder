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

set<string> ss_no_mark;
set<string> ss_with_mark;

int main(void) {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (s[0] == '!') {
            ss_with_mark.insert(s.substr(1));
        } else {
            ss_no_mark.insert(s);
        }
    }

    for (auto &ss : ss_no_mark) {
        if (ss_with_mark.find(ss) != ss_with_mark.end()) {
            cout << ss << endl;
            return 0;
        }
    }

    cout << "satisfiable" << endl;
    return 0;
}
