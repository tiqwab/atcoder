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

ll calc_score(map<int, int> &counter) {
    ll score = 0;
    for (int i = 1; i <= 9; i++) {
        ll acc = i;
        for (int j = 1; j <= counter[i]; j++) {
            acc *= 10;
        }
        score += acc;
    }
    return score;
}

int main(void) {
    ll K;
    cin >> K;
    string S, T;
    cin >> S >> T;

    map<int, int> cards;
    for (int i = 1; i <= 9; i++) {
        cards[i] = K;
    }

    map<int, int> count_s, count_t;
    for (char c : S) {
        count_s[c - '0'] += 1;
        cards[c - '0']--;
    }
    for (char c : T) {
        count_t[c - '0'] += 1;
        cards[c - '0']--;
    }

    ll win_patterns = 0;

    for (int s = 1; s <= 9; s++) {
        for (int t = 1; t <= 9; t++) {
            map<int, int> ss = count_s;
            ss[s] += 1;
            map<int, int> st = count_t;
            st[t] += 1;

            map<int, int> remain_cards = cards;
            ll sp = remain_cards[s];
            remain_cards[s]--;
            ll tp = remain_cards[t];
            remain_cards[t]--;

            ll score_s = calc_score(ss);
            ll score_t = calc_score(st);
            if (score_s > score_t) {
#ifdef DEBUG
                printf("s, t, score_s, score_t, pats: %d, %d, %lld, %lld, %lld\n", 
                        s, t, score_s, score_t, sp * tp);
#endif
                win_patterns += sp * tp;
            }
        }
    }

    printf("%.8f\n", ((double) win_patterns) / ((double) (K * 9 - 8) * (K * 9 - 9)));

    return 0;
}
