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
    int N;
    cin >> N;

    vector<int> as;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        as.push_back(a);
    }

    string S; 
    cin >> S;

    ll left_m_0 = 0;
    ll left_m_1 = 0;
    ll left_m_2 = 0;
    ll right_x_0 = 0;
    ll right_x_1 = 0;
    ll right_x_2 = 0;

    for (int i = 0; i < N; i++) {
        if (S[i] == 'X') {
            if (as[i] == 0) {
                right_x_0 += 1;
            } else if (as[i] == 1) {
                right_x_1 += 1;
            } else if (as[i] == 2) {
                right_x_2 += 1;
            }
        }
    }

#ifdef DEBUG
    printf("left_m_0: %lld\n", left_m_0);
    printf("left_m_1: %lld\n", left_m_1);
    printf("left_m_2: %lld\n", left_m_2);
    printf("right_x_0: %lld\n", right_x_0);
    printf("right_x_1: %lld\n", right_x_1);
    printf("right_x_2: %lld\n", right_x_2);
#endif

    ll ans = 0;

    for (int i = 0; i < N; i++) {
        if (S[i] == 'M') {
            if (as[i] == 0) {
                left_m_0 += 1;
            } else if (as[i] == 1) {
                left_m_1 += 1;
            } else if (as[i] == 2) {
                left_m_2 += 1;
            }
        } else if (S[i] == 'E') {
            ll acc = 0;
            if (as[i] == 0) {
                acc += left_m_0 * right_x_0 * 1;
                acc += left_m_0 * right_x_1 * 2;
                acc += left_m_0 * right_x_2 * 1;
                acc += left_m_1 * right_x_0 * 2;
                acc += left_m_1 * right_x_1 * 2;
                acc += left_m_1 * right_x_2 * 3;
                acc += left_m_2 * right_x_0 * 1;
                acc += left_m_2 * right_x_1 * 3;
                acc += left_m_2 * right_x_2 * 1;
            } else if (as[i] == 1) {
                acc += left_m_0 * right_x_0 * 2;
                acc += left_m_0 * right_x_1 * 2;
                acc += left_m_0 * right_x_2 * 3;
                acc += left_m_1 * right_x_0 * 2;
                acc += left_m_1 * right_x_1 * 0;
                acc += left_m_1 * right_x_2 * 0;
                acc += left_m_2 * right_x_0 * 3;
                acc += left_m_2 * right_x_1 * 0;
                acc += left_m_2 * right_x_2 * 0;
            } else if (as[i] == 2) {
                acc += left_m_0 * right_x_0 * 1;
                acc += left_m_0 * right_x_1 * 3;
                acc += left_m_0 * right_x_2 * 1;
                acc += left_m_1 * right_x_0 * 3;
                acc += left_m_1 * right_x_1 * 0;
                acc += left_m_1 * right_x_2 * 0;
                acc += left_m_2 * right_x_0 * 1;
                acc += left_m_2 * right_x_1 * 0;
                acc += left_m_2 * right_x_2 * 0;
            }
            ans += acc;
        } else if (S[i] == 'X') {
            if (as[i] == 0) {
                right_x_0 -= 1;
            } else if (as[i] == 1) {
                right_x_1 -= 1;
            } else if (as[i] == 2) {
                right_x_2 -= 1;
            }
        }
    }

    printf("%lld\n", ans);

    return 0;
}
