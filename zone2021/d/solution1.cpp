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
    string S;
    cin >> S;

    deque<char> deq;
    int dir = 1; // append back if dir == 1, otherwise append front

    for (int i = 0; i < (int) S.size(); i++) {
        const char c = S[i];
        if (c == 'R') {
            dir *= -1;
        } else {
            if (dir == 1) {
                if (deq.size() > 0 && deq[(int) deq.size() - 1] == c) {
                    deq.pop_back();
                } else {
                    deq.push_back(c);
                }
            } else {
                if (deq.size() > 0 && deq[0] == c) {
                    deq.pop_front();
                } else {
                    deq.push_front(c);
                }
            }
        }
    }

    if (dir != 1) {
        reverse(deq.begin(), deq.end());
    }

    for (auto c : deq) {
        printf("%c", c);
    }
    printf("\n");

    return 0;
}
