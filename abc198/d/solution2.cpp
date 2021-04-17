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

set<char> chars;
string s1, s2, s3;
ll ans1, ans2, ans3;

ll to_ll(const string s, map<char, int> &m) {
    ll ans = 0;
    for (int i = 0; i < (int) s.size(); i++) {
        char c = s[i];
        ans = ans * 10 + m[c];
    }
    return ans;
}

bool check(const vector<int> &acc, const int N) {
    auto it = chars.begin();
    map<char, int> m;
    for (int i = 0; i < N; i++) {
        m[*it] = acc[i];
        it++;
    }

    if (m[s1[0]] == 0 || m[s2[0]] == 0 || m[s3[0]] == 0) {
        return false;
    }

    ll l1 = to_ll(s1, m);
    ll l2 = to_ll(s2, m);
    ll l3 = to_ll(s3, m);

    if (l1 + l2 == l3) {
        ans1 = l1;
        ans2 = l2;
        ans3 = l3;
        return true;
    } else {
        return false;
    }
}

// use next_permutation
// there is no significant difference compared to solution1 in terms of execution time.
// (2296ms for solution1, 1698ms for solution2)
int main(void) {
    cin >> s1 >> s2 >> s3;

    for (auto c : s1) {
        chars.insert(c);
    }
    for (auto c : s2) {
        chars.insert(c);
    }
    for (auto c : s3) {
        chars.insert(c);
    }
    if ((int) chars.size() > 10) {
        cout << "UNSOLVABLE" << endl;
        return 0;
    }

    vector<int> vs;
    for (int i = 0; i < 10; i++) {
        vs.push_back(i);
    }

    bool ok = false;

    do {
        if (check(vs, chars.size())) {
            printf("%lld\n%lld\n%lld\n", ans1, ans2, ans3);
            ok = true;
            break;
        }
    } while (next_permutation(vs.begin(), vs.end()));

    if (!ok) {
        printf("UNSOLVABLE\n");
    }

    return 0;
}
