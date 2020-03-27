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

const ll MOD = ll(1e9 + 7);

// A: 1, C: 2, G: 3, T: 4
vector<vector<ll>> dp;

ll str_to_id(const string str) {
    ll id = 0;
    for (auto &c : str) {
        int x;
        if (c == 'A') x = 0;
        else if (c == 'C') x = 1;
        else if (c == 'G') x = 2;
        else x = 3;
        id = id * 4 + x;
    }
    return id;
}

string id_to_str(ll id) {
    string S;
    for (int i = 0; i < 3; i++) {
        int x = id % 4;
        char c;
        if (x == 0) c = 'A';
        else if (x == 1) c = 'C';
        else if (x == 2) c = 'G';
        else c = 'T';
        S += c;
        id /= 4;
    }
    reverse(S.begin(), S.end());
    return S;
}

bool check(const string last4) {
    if (last4.substr(1) == "AGC" ||
            last4.substr(1) == "GAC" ||
            last4.substr(1) == "ACG" ||
            (last4[0] == 'A' && last4[1] == 'G' && last4[3] == 'C') ||
            (last4[0] == 'A' && last4[2] == 'G' && last4[3] == 'C')) {
        return false;
    }
    return true;
}

void solve(const int N) {
    const vector<char> cs = {'A', 'C', 'G', 'T'};

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 64; j++) {
            const ll id = j;
            const string last3 = id_to_str(j);

            // printf("last3: %s, val: %lld\n", last3.c_str(), dp[i][id]);

            for (auto c : cs) {
                const string str = last3 + c;
                if (check(str)) {
                    const ll next_id = str_to_id(str.substr(1));
                    dp[i + 1][next_id] = (dp[i + 1][next_id] + dp[i][id]) % MOD;
                }
            }
        }
    }
}

int main(void) {
    int N;
    cin >> N;

    dp.resize(N + 1, vector<ll>(64, 0));
    dp[1][str_to_id("TTA")] = 1;
    dp[1][str_to_id("TTC")] = 1;
    dp[1][str_to_id("TTG")] = 1;
    dp[1][str_to_id("TTT")] = 1;

    solve(N);

    ll ans = 0;
    for (int i = 0; i < 64; i++) {
        ans = (ans + dp[N][i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}
