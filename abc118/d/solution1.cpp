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

const vector<int> ms = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

vector<int> as;
vector<int> dp;

inline int match_for(int x) {
    return ms[x];
}

int calc_max_digits(const int N, const vector<int> &as) {
    for (int i = 1; i <= N; i++) {
        for (auto &a : as) {
            int matches = match_for(a);
            if (i - matches >= 0 && dp[i - matches] >= 0) {
                chmax(dp[i], dp[i - matches] + 1);
            }
        }
    }
    return dp[N];
}

vector<int> solve(const int max_digits, const int N, const vector<int> &as) {
    vector<int> res;
    int cur_match = N;
    for (int i = 1; i <= max_digits; i++) {
        for (auto &a : as) {
            int req_match = match_for(a);
            if (cur_match - req_match >= 0 && dp[cur_match - req_match] == max_digits - i) {
                if (i == max_digits && cur_match - req_match != 0) {
                    // must consume all matches if this is the last digit.
                    continue;
                } else {
                    res.push_back(a);
                    cur_match -= req_match;
                    break;
                }
            }
        }
    }
    // assert(cur_match == 0);
    assert((int) res.size() == max_digits);
    return res;
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

    dp.resize(N + 1, -1);
    dp[0] = 0;

    int max_digits = calc_max_digits(N, as);
    // printf("max_digits: %d\n", max_digits);

    vector<int> ans = solve(max_digits, N, as);
    for (auto &a : ans) {
        printf("%d", a);
    }
    printf("\n");

    return 0;
}
