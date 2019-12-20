#include <algorithm>
#include <iostream>
#include <vector>

#include <stdlib.h>

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

const ll MOD = 1000000007;

vector<ll> toi(char c) {
    vector<ll> res;
    if(c == '?') {
        for (int i = 0; i < 10; i++) {
            res.push_back(i);
        }
    } else {
        res.push_back((ll) (c - '0'));
    }
    return res;
}

ll solve(const int pos, const vector<ll> &rems, const string &S) {
    if (pos >= (int) S.length()) {
        return rems[5];
    }

    vector<ll> my_rems((int) rems.size(), 0);
    vector<ll> vs = toi(S[pos]);
    for (auto v : vs) {
        ll acc = v;
        for (int i = 0; i < pos; i++) {
            acc = (acc * 10) % 13;
        }
        for (int i = 0; i < (int) rems.size(); i++) {
            // if ((i + acc) % 13 == 5) {
                my_rems[(i + acc) % 13] = (my_rems[(i + acc) % 13] + rems[i]) % MOD;
            // }
        }
    }

    // for (int i = 0; i < (int) my_rems.size(); i++) {
    //     cout << my_rems[i] << " ";
    // }
    // cout << endl;

    return solve(pos + 1, my_rems, S);
}

int main(void) {
    string S;
    cin >> S;
    reverse(S.begin(), S.end());

    vector<ll> xs(13, 0);
    vector<ll> vs = toi(S[0]);
    for (auto v : vs) {
        xs[v]++;
    }

    auto rems = solve(1, xs, S);

    // ll answer = 0;
    // for (int i = 0; i < (int) rems.size(); i++) {
    //     answer = (answer + rems[i]) % MOD;
    // }
    // cout << answer << endl;

    cout << rems << endl;

    return 0;
}
