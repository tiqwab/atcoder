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

bool cond(const int n) {
    vector<int> divs;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            if (i * i != n) {
                divs.push_back(n / i);
            }
        }
    }

    // printf("%d: ", n);
    // for (auto &d : divs) {
    //     cout << d << " ";
    // }
    // cout << endl;

    return ((int) divs.size()) == 8;
}

int main(void) {
    int N;
    cin >> N;

    int cnt = 0;
    for (int i = 1; i <= N; i += 2) {
        if (cond(i)) {
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}
