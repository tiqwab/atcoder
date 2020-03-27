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
    while (id != 0) {
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

ll solve(const int pos, const string last3, const int N) {
    const ll id = str_to_id(last3);

    if (pos == N) return 1LL;

    if (dp[pos][id] >= 0) {
        return dp[pos][id];
    }

    ll acc = 0;
    vector<char> cs = {'A', 'C', 'G', 'T'};
    for (auto &c : cs) {
        string str = last3 + c;
        if (!check(str)) {
            continue;
        }
        acc = (acc + solve(pos + 1, str.substr(1), N)) % MOD;
    }

    dp[pos][id] = acc;
    // printf("pos: %d, last3: %s, acc: %lld\n", pos, last3.c_str(), acc);
    return acc;
}

int main(void) {
    int N;
    cin >> N;

    dp.resize(N, vector<ll>(1000, -1));
    cout << solve(0, "ZZZ", N) << endl;

    return 0;
}
