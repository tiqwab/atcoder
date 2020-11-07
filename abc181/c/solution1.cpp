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

vector<int> xs;
vector<int> ys;

int gcd(int a, int b) {
    if (a > b) {
        return gcd(b, a);
    }
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

int main(void) {
    int N;
    cin >> N;

    xs.resize(N);
    ys.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> xs[i];
        cin >> ys[i];
    }

    auto f = [](int i, int j) {
        int diff_x_ij = xs[i] - xs[j];
        int diff_y_ij = ys[i] - ys[j];
        if (diff_x_ij == 0) {
            diff_y_ij /= abs(diff_y_ij);
        }
        if (diff_y_ij == 0) {
            diff_x_ij /= abs(diff_x_ij);
        }
        int gcd_ij = gcd(abs(diff_x_ij), abs(diff_y_ij));
        diff_x_ij /= gcd_ij;
        diff_y_ij /= gcd_ij;
        return make_pair(diff_x_ij, diff_y_ij);
    };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (i == j || j == k || k == i) {
                    continue;
                }

#ifdef DEBUG
                printf("(%d, %d), (%d, %d), (%d, %d)\n", xs[i], ys[i], xs[j], ys[j], xs[k], ys[k]);
#endif
                auto one = f(i, j);
                auto two = f(j, k);
#ifdef DEBUG
                printf("one: (%d, %d), two: (%d, %d)\n", one.first, one.second, two.first, two.second);
#endif

                if (one.first == two.first && one.second == two.second) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;
    
    return 0;
}
