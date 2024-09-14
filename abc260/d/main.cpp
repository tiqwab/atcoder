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

int main(void) {
    int N, K;
    cin >> N >> K;

    vector<int> cards;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        cards.push_back(x);
    }

    map<int, vector<int>> fields;
    vector<int> ans(N, -1);

    for (int i = 0; i < N; i++) {
        const int card = cards[i];
        auto it = fields.lower_bound(card);
        if (it == fields.end()) {
            if (K == 1) {
                ans[card - 1] = i + 1;
            } else {
                fields[card] = {card};
            }
        } else {
            auto tmp = fields.extract(it);
            tmp.mapped().push_back(card);
            if ((int) tmp.mapped().size() == K) {
                for (auto x : tmp.mapped()) {
                    ans[x - 1] = i + 1;
                }
            } else {
                tmp.key() = card;
                fields.insert(move(tmp));
            }
        }
    }

    for (auto x : ans) {
        printf("%d\n", x);
    }

    return 0;
}
