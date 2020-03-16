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

vector<char> cs;

void solve(string &s, const int pos, const int kinds, const int N) {
    // printf("pos: %d, kinds: %d\n", pos, kinds);
    if (pos == N) {
        cout << s << endl;
        return;
    }

    for (int i = 0; i < kinds; i++) {
        char c = cs[i];
        s.push_back(c);
        solve(s, pos + 1, kinds, N);
        s.pop_back();
    }

    s.push_back(cs[kinds]);
    solve(s, pos + 1, kinds + 1, N);
    s.pop_back();
}

int main(void) {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cs.push_back('a' + i);
    }

    string str = "";
    solve(str, 0, 0, N);

    return 0;
}
