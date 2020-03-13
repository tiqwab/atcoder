#include <algorithm>
#include <iostream>
#include <queue>
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

int main(void) {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    int slen = (int) S.size();

    vector<pair<char, int>> compress;
    if (S[0] == '0') {
        compress.push_back({'1', 0});
    }
    {
        char c = S[0];
        int count = 1;
        for (int i = 1; i < slen; i++) {
            if (S[i] == c) {
                count++;
            } else {
                compress.push_back({c, count});
                c = S[i];
                count = 1;
            }
        }
        compress.push_back({c, count});
    }
    if (compress[(int) compress.size() - 1].first == '0') {
        compress.push_back({'1', 0});
    }

    // for (auto &p : compress) {
    //     printf("%c: %d\n", p.first, p.second);
    // }
    // printf("\n");

    int ans = 0;
    int acc = 0;
    int cnt = 0;
    queue<pair<char, int>> q;

    acc += compress[0].second;
    q.push(compress[0]);
    for (int i = 1; i < (int) compress.size(); i++) {
        if (cnt >= 2 * K) {
            chmax(ans, acc);
            acc -= q.front().second;
            q.pop();
            acc -= q.front().second;
            q.pop();
            cnt -= 2;
        }
        acc += compress[i].second;
        q.push(compress[i]);
        cnt++;
    }
    chmax(ans, acc);

    cout << ans << endl;

    return 0;
}
