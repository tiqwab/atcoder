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

vector<int> ls;

int main(void) {
    int N;
    cin >> N;

    ls.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> ls[i];
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                int a = ls[i];
                int b = ls[j];
                int c = ls[k];
                if (a + b > c && a + c > b && b + c > a) {
                    if (a != b && b != c && c != a) {
                        ans++;
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
