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

    vector<char> front;
    vector<char> back;
    int dir = 1; // append back if dir == 1, otherwise append front

    for (int i = 0; i < (int) S.size(); i++) {
        const char c = S[i];
        if (c == 'R') {
            dir *= -1;
        } else {
            if (dir == 1) {
                if (back.size() > 0 && back.back() == c) {
                    back.pop_back();
                } else {
                    back.push_back(c);
                }
            } else {
                if (front.size() > 0 && front.back() == c) {
                    front.pop_back();
                } else {
                    front.push_back(c);
                }
            }
        }
    }

    if (dir == 1) {
        reverse(front.begin(), front.end());
        for (auto c : front) {
            printf("%c", c);
        }
        for (auto c : back) {
            printf("%c", c);
        }
    } else {
        reverse(back.begin(), back.end());
        for (auto c : back) {
            printf("%c", c);
        }
        for (auto c : front) {
            printf("%c", c);
        }
    }
    printf("\n");

    return 0;
}
