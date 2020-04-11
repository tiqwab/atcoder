#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <string.h>
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

const vector<int> ms = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const string NA = "$";

vector<int> as;
vector<string> dp;

inline int match_for(int x) {
    return ms[x];
}

int cmp(const string &a, const string &b) {
    if ((int) a.size() != (int) b.size()) {
        return ((int) a.size() > (int) b.size()) ? 1 : -1;
    }
    return strncmp(a.c_str(), b.c_str(), (int) a.size());
}

string solve(const int N, const vector<int> &as) {
    for (int i = 1; i <= N; i++) {
        for (auto a : as) {
            int req_match = match_for(a);
            if (i - req_match >= 0 && dp[i - req_match] != NA) {
                string cand = dp[i - req_match] + to_string(a);
                if (cmp(cand, dp[i]) > 0) {
                    dp[i] = move(cand);
                }
            }
        }
    }
    return dp[N];
}

int main(void) {
    int N, M;
    cin >> N >> M;

    as.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> as[i];
    }
    sort(as.begin(), as.end());
    reverse(as.begin(), as.end());

    dp.resize(N + 1, NA);
    dp[0] = "";

    string ans = solve(N, as);
    cout << ans << endl;

    return 0;
}
