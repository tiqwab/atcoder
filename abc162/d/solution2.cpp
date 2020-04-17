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

vector<int> rs;
vector<int> gs;
vector<int> bs;

ll solve(const string S, const int N) {
    ll ans = 0;
    ll exclusive_cnt = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int k = j + (j - i);
            if (k >= N) continue;
            if (S[i] != S[j] && S[j] != S[k] && S[k] != S[i]) exclusive_cnt++;
        }
    }

    ans = rs.size() * gs.size() * bs.size() - exclusive_cnt;
    return ans;
}

// Based on the soltuion pdf.
int main(void) {
    int N;
    cin >> N;
    string S;
    cin >> S;

    for (int i = 0; i < N; i++) {
        char c = S[i];
        if (c == 'R') {
            rs.push_back(i);
        } else if (c == 'G') {
            gs.push_back(i);
        } else {
            bs.push_back(i);
        }
    }

    cout << solve(S, N) << endl;

    return 0;
}
