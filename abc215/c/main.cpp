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

void rec(int cur, string &acc, set<string> &se, multiset<char> chars, const int slen, const int K) {
    if (cur == slen) {
        se.insert(acc);
        return;
    }

    for (auto c : chars) {
        multiset<char> next_chars = chars;
        next_chars.erase(next_chars.find(c));
        acc.push_back(c);
        rec(cur + 1, acc, se, next_chars, slen, K);
        acc.pop_back();
    }
}

int main(void) {
    string S;
    int K;
    cin >> S >> K;
    const int slen = (int) S.size();

    set<string> se;
    multiset<char> chars;
    for (int i = 0; i < slen; i++) {
        chars.insert(S[i]);
    }

    string acc = "";
    rec(0, acc, se, chars, slen, K);

    {
        auto it = se.begin();
        for (int i = 1; i < K; i++) {
            it++;
        }
        cout << *it << endl;
    }

    return 0;
}
