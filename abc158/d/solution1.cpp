#include <algorithm>
#include <iostream>
#include <deque>
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

int main(void) {
    string S;
    cin >> S;
    int Q;
    cin >> Q;

    deque<char> deq;
    for (int i = 0; i < (int) S.size(); i++) {
        deq.push_back(S[i]);
    }

    int direction = 1;

    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            direction *= -1;
        } else {
            int f;
            char c;
            cin >> f >> c;
            if (direction == 1) {
                if (f == 1) {
                    // add top
                    deq.push_front(c);
                } else {
                    // add back
                    deq.push_back(c);
                }
            } else {
                if (f == 1) {
                    // add top
                    deq.push_back(c);
                } else {
                    // add back
                    deq.push_front(c);
                }
            }
        }
    }

    // It is OK.
    int siz = (int) deq.size();
    for (int i = 0; i < siz; i++) {
        char c;
        if (direction > 0) {
            c = deq.front();
            deq.pop_front();
        } else {
            c = deq.back();
            deq.pop_back();
        }
        printf("%c", c);
    }
    printf("\n");

    // It is also OK.
    // int siz = (int) deq.size();
    // if (direction > 0) {
    //     for (int i = 0; i < siz; i++) {
    //         printf("%c", deq[i]);
    //     }
    // } else {
    //     for (int i = siz - 1; i >= 0; i--) {
    //         printf("%c", deq[i]);
    //     }
    // }
    // printf("\n");

    // The below code doesn't work.
    // The reason seems that deque doesn't support pointer operations such as `reverse`.
    // if (direction < 0) {
    //     reverse(deq.begin(), deq.end());
    // }
    // for (int i = 0; i < (int) deq.size(); i++) {
    //     char c = deq.push_front();
    //     deq.pop_front();
    //     printf("%c", deq[i]);
    // }
    // for (ll i = 0; i < (ll) deq.size(); i++) {
    //     printf("%c", deq[i]);
    // }
    // printf("\n");

    return 0;
}
